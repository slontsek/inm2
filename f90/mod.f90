module mod
        implicit none
        private
        public::test
        integer::const=100
contains
        subroutine test()
                print *, "Running test", const
        end subroutine
end module
