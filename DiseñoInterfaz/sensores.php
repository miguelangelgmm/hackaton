<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Sensores</title>
    <link rel="stylesheet" href="sensores.css" />
</head>

<body>
    <?php

    class BaseDatos extends SQLite3{
        function __construct()
        {
            $this->open("basededatos.db");
        }
    }
    $db = new BaseDatos();

    $sql = "SELECT * FROM sensores";

    $query = $db->query($sql);
    while ($fila = $query->fetchArray()) {
        $temperatura = $fila["temperatura"];
        $humedad = $fila["humedad"];
        $humedadTierra = $fila["humedadTierra"];
        $clima = $fila["clima"];
        $tiempo = $fila["tiempo"];
    }
    ?>
    
    <div class="card">
        <header>
            <div>
                <a href="index.html"><img id="logo" src="imgWeb/logo.png" alt="logo" /></a>
            </div>
            <nav>
                <ul class="menu-grande">
                    <li><a href="index.html">home</a></li>
                    <li><a>sensores</a></li>
                    <li><a href="activadores.html">activadores</a></li>
                    <li><a href="imagenes.html">imágenes</a></li>
                    <li><a href="graficas">gráficas</a></li>
                </ul>
            </nav>
        </header>
        <main>
            <ul>
                <li>
                    <div class="temperatura">
                        <h2>Temperatura</h2>
                        <img src="imgWeb/Sensores/termometro.png" alt="temperatura" />
                        <p id="Temperatura-Text"><?php echo $temperatura?><span>ºC</span></p>
                    </div>
                </li>
                <li>
                    <div class="clima">
                        <h2>Clima</h2>
                        <img src="imgWeb/Sensores/clima.png" alt="clima" />
                        <p id="clima-text"><?php echo $clima?></p>
                    </div>
                </li>
                <li>
                    <div class="humedad">
                        <h2>Humedad</h2>
                        <img src="imgWeb/Sensores/nube.png" alt="humedad" />
                        <p id="humedad-text"><?php echo $humedad?><span>%</span></p>
                    </div>
                </li>
                <li>
                    <div class="viento">
                        <h2>Viento</h2>
                        <img src="imgWeb/Sensores/clima(1).png" alt="viento" />
                        <p id="viento-text"><?php echo $tiempo?><span>km/h</span></p>
                    </div>
                </li>
                <li>
                    <div class="humedad-tierra">
                        <h2>Humedad de la Tierra</h2>
                        <img src="imgWeb/Sensores/planta.png" alt="humedad-tierra" />
                        <p id="humedad-tierra-text"><?php echo $humedadTierra ?><span>%</span></p>
                    </div>
                </li>
            </ul>
        </main>
    </div>
    <img class="tomate" src="imgWeb/home/fondo.png" alt="tomate" />
    <img class="naranja" src="imgWeb/home/naranjafondo.png" alt="naranja" />

</body>

</html>