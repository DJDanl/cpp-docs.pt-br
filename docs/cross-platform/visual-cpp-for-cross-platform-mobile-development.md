---
title: Desenvolvimento de tecnologia móvel multiplataforma com C++
ms.date: 11/14/2019
ms.assetid: 0bb872d6-981b-4c96-9143-fcec5336bf0d
ms.openlocfilehash: dd2ea678d7689fac60bcee3555772b87df06e31b
ms.sourcegitcommit: a673f6a54cc97e3d4cd032b10aa8dce7f0539d39
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2020
ms.locfileid: "78177538"
---
# <a name="cross-platform-mobile-development-with-c"></a>Desenvolvimento de tecnologia móvel multiplataforma com C++

Você pode criar aplicativos C++ nativos para dispositivos IOS, Android e Windows usando as ferramentas de plataforma cruzada disponíveis no Visual Studio. O **desenvolvimento móvel C++ com** o é uma carga de trabalho disponível no instalador do Visual Studio. Ele instala os SDKs e as ferramentas de que você precisa para o desenvolvimento de plataforma cruzada de bibliotecas compartilhadas e aplicativos nativos. Quando ele é instalado, você pode usar C++ o para criar um código que é executado em dispositivos e plataformas Ios e Android, Windows, Windows Store e Xbox.

Escrever código para várias plataformas muitas vezes é frustrante. As linguagens de desenvolvimento principais e as ferramentas para iOS, Android e Windows são diferentes em cada plataforma. No entanto, todas as plataformas dão suporte à gravação de código em C++. É o denominador comum que pode permitir a reutilização de código principal entre plataformas. Código nativo gravado em C++ pode ser mais eficaz e resistente à engenharia reversa. A reutilização de código pode economizar tempo e esforço durante a criação de aplicativos para várias plataformas.

O desenvolvimento C++ usando para o desenvolvimento móvel de plataforma cruzada tem várias vantagens:

- **Fácil instalação.** O instalador do Visual Studio obtém e instala as ferramentas de terceiros necessárias e SDKs que você precisa para compilar bibliotecas ou aplicativos para Android e iOS. A configuração e a configuração são simples e principalmente automáticas.

- **Um ambiente de build poderoso e familiar.** Crie soluções de plataforma cruzada compartilháveis e projetos facilmente com modelos do Visual Studio. Gerencie as propriedades de todos os projetos usando uma interface comum. Edite todos os seus códigos no editor do Visual Studio e desfrute da plataforma cruzada interna IntelliSense para conclusão de código e realce de erros.

- **Experiência de depuração unificada.** Use as ferramentas de depuração de classe mundial no Visual Studio para assistir e percorrer C++ o código em todas as plataformas: dispositivos e emuladores Android, simuladores e dispositivos do IOS e dispositivos e emuladores Windows ou Windows Store.

## <a name="get-the-tools"></a>Obter as ferramentas

O desenvolvimento móvel C++ com o é uma carga de trabalho instalável que vem com o Visual Studio. Para obter pré-requisitos e instruções de instalação, consulte [instalar o desenvolvimento móvel de plataforma C++cruzada com ](../cross-platform/install-visual-cpp-for-cross-platform-mobile-development.md)o. Para compilar código para iOS, você também precisa de um computador Mac e uma Conta de Desenvolvedor do Apple iOS. Para obter mais informações, confira [Instalar e configurar ferramentas de build usando o iOS](../cross-platform/install-and-configure-tools-to-build-using-ios.md).

## <a name="come-up-to-speed"></a>Excelente operação

Se você estiver vindo do desenvolvimento Android ou iOS, temos materiais excelente sobre como começar. O Visual Studio é um ambiente de desenvolvimento completo expressivo e capaz. Para saber como usá-lo, experimente a [Introdução para desenvolvedores do Android](/previous-versions/windows/apps/dn275875\(v=win.10\)) ou a [Introdução para desenvolvedores do iOS](/previous-versions/windows/apps/jj657966\(v=win.10\)). Esses artigos apresentarão o Visual Studio e os conceitos necessários para desenvolver aplicativos de plataforma cruzada para Windows e Windows Store. Para começar a escrever seu primeiro aplicativo de plataforma cruzada para iOS e Android, consulte [criar um aplicativo OpenGL ES no Android e Ios](../cross-platform/build-an-opengl-es-application-on-android-and-ios.md).

O desenvolvimento móvel com C++ carga de trabalho inclui vários modelos para ajudá-lo a começar a usar seus aplicativos:

- Aplicativo de Atividade Nativa (Android)

  Cria um aplicativo C++ OpenGL completo como um projeto de Atividade Nativa do Android.

- Aplicativo OpenGLES (Android, iOS)

  Cria uma solução com um conjunto de projetos para compilar um aplicativo de Atividade Nativa do Android e um aplicativo iOS. Estes aplicativos usam bibliotecas específicas da plataforma criada ao usar o código C++ OpenGL ES comum para desenhar o mesmo cubo rotatório em cada aplicativo.

- Biblioteca Compartilhada (Android, iOS)

  Cria uma solução com projetos para criar um arquivo de biblioteca Android dinâmica (.so) e um arquivo de biblioteca estática (.a) do iOS com código C++ comum em um projeto compartilhado.

- Aplicativo Básico (Android, Ant)

  Cria um projeto de aplicativo do Android "Olá, mundo" que usa somente um código-fonte Java e o sistema de build Ant.

- Aplicativo Básico (Android, Gradle)

  Cria um projeto de aplicativo do Android "Olá, mundo" que usa somente um código-fonte Java e o sistema de build Gradle.

- Biblioteca Básica (Android, Ant)

  Cria um projeto de biblioteca do Android "Olá, mundo" que usa somente um código-fonte Java e o sistema de build Ant.

- Biblioteca Básica (Android, Gradle)

  Cria um projeto de biblioteca do Android "Olá, mundo" que usa somente um código-fonte Java e o sistema de build Gradle.

- Biblioteca Dinâmica Compartilhada (Android)

  Cria um arquivo de biblioteca dinâmica Android (.so) usando código C++.

- Aplicativo OpenGLES 2 (iOS)

  Cria uma solução com um conjunto de projetos para compilar um aplicativo iOS OpenGL ES 2. O aplicativo usa uma biblioteca de código C++ OpenGL ES para desenhar o cubo giratório em um aplicativo iOS. Este aplicativo pode ser um bom ponto de partida para ver como importar bibliotecas C++ para seu aplicativo iOS.

- Biblioteca Estática (Android)

  Cria um projeto para compilar uma biblioteca estática para Android. Você pode apenas vincular uma biblioteca dinâmica em um aplicativo Android, mas você pode vincular qualquer número de bibliotecas estáticas.

- Biblioteca Estática (iOS)

  Cria um projeto para compilar uma biblioteca estática para iOS.

- Projeto do Makefile (Android)

  Cria um wrapper de projeto para seus próprios projetos de makefile Android.

## <a name="try-out-sample-code"></a>Testar o código de exemplo

Baixe exemplos que mostram como criar bibliotecas de código compartilhado que você pode usar em aplicativos Windows, Android e iOS. E veja exemplos de como criar aplicativos de atividades nativas completos para Android. Para começar, confira [Exemplos de desenvolvimento móvel multiplataforma](../cross-platform/cross-platform-mobile-development-examples.md).

## <a name="see-also"></a>Confira também

[Instalar o desenvolvimento móvel de plataforma cruzada com C++ ](../cross-platform/install-visual-cpp-for-cross-platform-mobile-development.md) o\
[Instalar e configurar ferramentas para compilar usando o iOS](../cross-platform/install-and-configure-tools-to-build-using-ios.md)\
[Criar um aplicativo de atividade nativa do Android](../cross-platform/create-an-android-native-activity-app.md)\
[Criar um aplicativo OpenGL ES no Android e iOS](../cross-platform/build-an-opengl-es-application-on-android-and-ios.md)\
[Exemplos de desenvolvimento móvel multiplataforma](../cross-platform/cross-platform-mobile-development-examples.md)
