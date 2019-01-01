#pragma once

#include <thread>
#include <iostream>
#include <chrono>

namespace drkrBase
{
    // Based on https://www.fluentcpp.com/2018/12/28/timer-cpp/
    class Timer
    {
    public:
        template<typename Function>
        void setTimeout( Function aFunction, int aDelay );

        template<typename Function>
        void setInterval( Function aFunction, int aInterval );

        void stop();

    private:
        bool mTimerActive = true;
    };

    template<typename Function>
    void Timer::setTimeout( Function aFunction, int aDelay )
    {
        this->mTimerActive = true;
        std::thread lThread( [=]()
        {
            if( !this->mTimerActive )
            {
                return;
            }
            
            std::this_thread::sleep_for( std::chrono::milliseconds( aDelay ) );

            if( !this->mTimerActive )
            {
                return;
            }

            aFunction();
        } );
        lThread.detach();
    }

    template<typename Function>
    void Timer::setInterval( Function aFunction, int aInterval )
    {
        this->mTimerActive = true;
        std::thread lThread( [=]()
        {
            while( true )
            {
                if( !mTimerActive )
                {
                    return;
                }

                std::this_thread::sleep_for( std::chrono::milliseconds( aInterval ) );

                if( !mTimerActive )
                {
                    return;
                }
                aFunction();
            }
        } );
        lThread.detach();
    }

    void Timer::stop()
    {
        this->mTimerActive = false;
    }
}