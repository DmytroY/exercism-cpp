namespace targets {
// TODO: Insert the code for the alien class here
    class Alien {
        private:
             int health{3};
        public:
            int x_coordinate;
            int y_coordinate;       
            Alien(int x, int y){
                health = 3;
                x_coordinate = x;
                y_coordinate = y;
            }

            int get_health(){
                return health;
            }

            bool hit(){
                if (health > 0) health--;
                return true;
            }

            bool is_alive(){
                if (health > 0) return true;
                return false;
            }

            bool teleport(int x, int y){
                x_coordinate = x;
                y_coordinate = y;
                return true;
            }

            bool collision_detection(Alien alien2){
                if (x_coordinate == alien2.x_coordinate && y_coordinate == alien2.y_coordinate) return true;
                return false;
            }
    };

}  // namespace targets