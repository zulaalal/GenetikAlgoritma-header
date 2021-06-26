
std::vector<std::string> split(const std::string &line, char delim)
{
    std::vector<std::string> elems;
    std::stringstream ss(line);
    std::string item;
    while (getline(ss, item, delim))
    {  
        elems.push_back(item);
    }
    return elems;
}

void readTourFromFile(tour_t &tour, std::ifstream &file)
{
    int n;
    float x, y;
    while (file >> n >> x >> y)
    {        
       
        n = n-1;
        tour.cities[n] = city_t(x, y, n);
    }
}


int find_option( int argc, char **argv, const char *option )
{
    for( int i = 1; i < argc; i++ )
        if( strcmp( argv[i], option ) == 0 )
            return i;
    return -1;
}


char *read_string( int argc, char **argv, const char *option, char *default_value )
{
    int iplace = find_option( argc, argv, option );
    if( iplace >= 0 && iplace < argc-1 )
        return argv[iplace+1];
    return default_value;
}
