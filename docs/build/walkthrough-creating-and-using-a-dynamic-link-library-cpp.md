---
title: "Instru&#231;&#245;es passo a passo: criando e usando uma biblioteca de v&#237;nculo din&#226;mico (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "11/17/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DLLs [C++], explicações passo a passo"
  - "bibliotecas [C++], DLLs"
ms.assetid: 3ae94848-44e7-4955-bbad-7d40f493e941
caps.latest.revision: 36
caps.handback.revision: 36
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: criando e usando uma biblioteca de v&#237;nculo din&#226;mico (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este passo a passo mostra como criar uma biblioteca de vínculo dinâmico \(DLL\) para uso com um aplicativo C\+\+. Usando uma biblioteca é uma ótima maneira de reutilizar o código. Em vez de reimplementar as mesmas rotinas em todos os programas que você cria, você gravá\-los uma vez e, em seguida, fazer referência a eles, aplicativos que requerem a funcionalidade. Colocando o código na DLL, você economiza espaço em cada aplicativo que faz referência a ele e você pode atualizar a DLL sem recompilar todos os aplicativos que o utilizam. Para obter mais informações sobre DLLs, consulte [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md).  
  
 Este passo a passo apresenta estas tarefas:  
  
-   Crie um projeto DLL.  
  
-   Adicione uma classe para a DLL que exporta as funções estáticas.  
  
-   Crie um projeto de aplicativo de console.  
  
-   Use as funções exportadas pela DLL no aplicativo de console.  
  
-   Execute o aplicativo concluído.  
  
 Este passo a passo cria uma DLL que pode ser chamada de aplicativos que usam convenções de chamada de C\+\+. Isso exige a DLL e o aplicativo cliente a ser criado usando o mesmo conjunto de ferramentas de compilador, para que coincidam com as convenções de nomenclatura internas. Também é possível criar DLLs que podem ser chamados de aplicativos escritos em outras linguagens e compilado usando outros compiladores usando a convenção de chamada de C. Para obter mais informações sobre a especificação de vinculação C, consulte [Exportando funções do C\+\+ a serem usadas em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md). Para obter informações sobre como criar DLLs para uso com outras linguagens, consulte [Chamando funções DLL a partir de aplicativos Visual Basic](../build/calling-dll-functions-from-visual-basic-applications.md).  
  
 Este passo a passo simple usa uma solução combinada que contém a DLL e o aplicativo cliente e usa vinculação implícita em tempo de carregamento para importar as funções de DLLs. Uma situação mais comum envolve DLLs de terceiros que não são criados como parte de sua solução, ou que usam vinculação explícita para carregar as DLLs em tempo de execução em vez de em tempo de carregamento. Para obter mais informações sobre vinculação implícita e explícita de vinculação, consulte [Determinando qual método de associação usar](../build/determining-which-linking-method-to-use.md).  
  
## Pré-requisitos  
 Este tópico pressupõe que você compreenda os fundamentos da linguagem C\+\+ e os conceitos básicos de como usar o Visual Studio IDE. Instale os componentes do Visual C\+\+ no Visual Studio para usar este passo a passo.  
  
### Para criar um projeto DLL \(biblioteca\) de vínculo dinâmico  
  
1.  Na barra de menus, escolha **arquivo**, **novo**, **projeto**.  
  
2.  No painel esquerdo do **novo projeto** caixa de diálogo caixa, expanda **instalados**, **modelos**, **Visual C\+\+**, e, em seguida, selecione **Win32**.  
  
3.  No painel central, selecione **aplicativo do Console Win32**.  
  
4.  Especifique um nome para o projeto — por exemplo, **MathLibrary**— no **nome** caixa. Especifique um nome para a solução — por exemplo, **MathLibraryAndClient**— no **nome da solução** caixa. Escolha o botão **OK**.  
  
5.  No **Visão geral** página do **Win32 Application Wizard** caixa de diálogo, escolha o **próximo** botão.  
  
6.  Sobre o **configurações do aplicativo** página em **tipo de aplicativo**, selecione **DLL**.  
  
7.  Escolha o **Concluir** botão para criar o projeto.  
  
### Para adicionar uma classe para a biblioteca de vínculo dinâmico  
  
1.  Para criar um arquivo de cabeçalho para uma nova classe, na barra de menus, escolha **projeto**, **Add New Item**. No **Add New Item** caixa de diálogo, no painel esquerdo, selecione **Visual C\+\+**. No painel central, selecione **arquivo de cabeçalho \(. h\)**. Especifique um nome para o arquivo de cabeçalho — por exemplo, **MathLibrary.h**— e, em seguida, escolha o **Add** botão. Um arquivo de cabeçalho em branco é exibido.  
  
2.  Substitua o conteúdo do arquivo de cabeçalho com este código:  
  
    ```cpp  
    // MathLibrary.h - Contains declaration of Function class  
    #pragma once  
  
    #ifdef MATHLIBRARY_EXPORTS  
    #define MATHLIBRARY_API __declspec(dllexport)   
    #else  
    #define MATHLIBRARY_API __declspec(dllimport)   
    #endif  
  
    namespace MathLibrary  
    {  
        // This class is exported from the MathLibrary.dll  
        class Functions  
        {  
        public:  
            // Returns a + b  
            static MATHLIBRARY_API double Add(double a, double b);  
  
            // Returns a * b  
            static MATHLIBRARY_API double Multiply(double a, double b);  
  
            // Returns a + (a * b)  
            static MATHLIBRARY_API double AddMultiply(double a, double b);  
        };  
    }  
    ```  
  
     Esse código declara um namespace, **MathLibrary**,  que contém uma classe chamada **funções** que contém funções de membro para executar algumas operações matemáticas.  
  
     Observe as instruções do pré\-processador na parte superior do arquivo. Por padrão, o modelo de novo projeto para uma DLL adiciona `PROJECTNAME`EXPORTS de símbolos de pré\-processador definidos para o projeto DLL lista. Neste exemplo, **MATHLIBRARY\_EXPORTS** é definido quando o **MathLibrary** DLL projeto é compilado. Quando o **MATHLIBRARY\_EXPORTS** símbolo é definido, o **MATHLIBRARY\_API** conjuntos de símbolos de `__declspec(dllexport)` modificador nas declarações de função de membro neste código. Esse modificador informa ao compilador e vinculador para exportar uma função ou variável da DLL para que ele pode ser usado por outros aplicativos. Quando **MATHLIBRARY\_EXPORTS** é indefinido — por exemplo, quando o arquivo de cabeçalho é incluído por um aplicativo cliente —**MATHLIBRARY\_API** define o `__declspec(dllimport)` modificador nas declarações de função de membro. Esse modificador otimiza a importação da função em um aplicativo. Para obter mais informações, consulte [dllexport, dllimport](../cpp/dllexport-dllimport.md).  
  
    > [!NOTE]
    >  Se você estiver criando o projeto DLL na linha de comando, use o **\/D** opção de compilador para definir o **MATHLIBRARY\_EXPORTS** símbolo.  
  
3.  No **MathLibrary** project no **Solution Explorer**, no **arquivos de origem** pasta, abra **MathLibrary.cpp**.  
  
4.  Implementar os membros de **funções** classe no arquivo de origem. Substitua o conteúdo da **MathLibrary.cpp** arquivo pelo código a seguir:  
  
    ```cpp  
    // MathLibrary.cpp : Defines the exported functions for the DLL application.  
    // Compile by using: cl /EHsc /DMATHLIBRARY_EXPORTS /LD MathLibrary.cpp  
  
    #include "stdafx.h"  
    #include "MathLibrary.h"  
  
    namespace MathLibrary  
    {  
        double Functions::Add(double a, double b)  
        {  
            return a + b;  
        }  
  
        double Functions::Multiply(double a, double b)  
        {  
            return a * b;  
        }  
  
        double Functions::AddMultiply(double a, double b)  
        {  
            return a + (a * b);  
        }  
    }  
    ```  
  
5.  Para verificar se tudo está funcionando até agora, compile a biblioteca de vínculo dinâmico escolhendo **criar**, **Build Solution** na barra de menus.  A saída deve ter esta aparência:  
  
    ```Output  
    1 >---compilação iniciada: projeto: MathLibrary, configuração: Debug Win32---1 > Stdafx 1 > dllmain.cpp 1 > 1 MathLibrary.cpp > Criando biblioteca c:\users\username\documents\visual studio 2015\Projects\MathLibraryAndClient\Debug\MathLibrary.lib e objeto c:\users\username\documents\visual studio 2015\Projects\MathLibraryAndClient\Debug\MathLibrary.exp 1 > MathLibrary.vcxproj -> c:\users\username\documents\visual studio 2015\Projects\MathLibraryAndClient\Debug\MathLibrary.dll === de compilação : 1 com êxito, 0 falhou, 0 atualizadas, 0 ignorado ===  
    ```  
  
    > [!NOTE]
    >  Se você estiver usando uma edição Express que não exibe um **criar** menu na barra de menus, escolha **ferramentas**, **configurações**, **Configurações avançadas** para habilitá\-lo e, em seguida, escolha **criar**, **Build Solution**.  
  
    > [!NOTE]
    >  Se você estiver criando um projeto na linha de comando, use o **\/D** opção de compilador para definir o projeto `PROJECTNAME`símbolo do pré\-processador \_EXPORTS. Use o **\/LD** opção de compilador para especificar que o arquivo de saída deve ser uma DLL. Para obter mais informações, consulte [\/MD, \/MT, \/LD \(usar biblioteca em tempo de execução\)](../build/reference/md-mt-ld-use-run-time-library.md). Use o **\/EHsc** opção de compilador habilitar tratamento de exceções C\+\+. Para obter mais informações, consulte [\/EH \(modelo de tratamento de exceções\)](../build/reference/eh-exception-handling-model.md).  
  
     Parabéns, você criou uma DLL usando o Visual C\+\+\! Em seguida, você criará um aplicativo cliente que usa as funções exportadas pela DLL.  
  
### Para criar um aplicativo que faça referência à DLL  
  
1.  Para criar um aplicativo C\+\+ que usa a DLL que você acabou de criar, na barra de menus, escolha **arquivo**, **novo**, **projeto**.  
  
2.  No painel esquerdo do **novo projeto** caixa de diálogo, expanda **instalados**, **modelos**, **Visual C\+\+**, e, em seguida, selecione **Win32**.  
  
3.  No painel central, selecione **aplicativo do Console Win32**.  
  
4.  Especifique um nome para o projeto — por exemplo, **MathClient**— no **nome** caixa.  
  
5.  Escolha o botão suspenso no final o **solução** de controle e, em seguida, selecione **Adicionar à solução** na lista suspensa. Isso adiciona o novo projeto para a mesma solução que contém a DLL. Escolha o botão **OK**.  
  
6.  No **Visão geral** página do **Win32 Application Wizard** caixa de diálogo, escolha o **próximo** botão.  
  
7.  Sobre o **configurações do aplicativo** página em **tipo de aplicativo**, selecione **aplicativo de Console**.  
  
8.  Escolha o **Concluir** botão para criar o projeto.  
  
### Para usar a funcionalidade da biblioteca de classes no aplicativo  
  
1.  Quando terminar o Assistente de aplicativo Win32, um projeto de aplicativo de console mínimo é criado para você. O nome do arquivo de origem principal é o mesmo que o nome do projeto que você escolheu anteriormente. Neste exemplo, ele é chamado **MathClient.cpp**.  
  
2.  Para usar as rotinas matemáticas criadas na DLL, você deve fazer referência à DLL em seu aplicativo. Para fazer isso, sob o **MathClient** project no **Solution Explorer**, selecione o **referências** item. Na barra de menus, escolha **projeto**, **Adicionar referência**.  
  
    > [!NOTE]
    >  Em versões anteriores do Visual Studio, as referências são adicionadas ao seu projeto de maneira diferente. Selecione o **MathClient** project no **Solution Explorer**, e, em seguida, na barra de menus, escolha **projeto**, **referências**. No **páginas de propriedade** caixa de diálogo caixa, expanda o **Propriedades comuns** nó, selecione **estrutura e referências**, e, em seguida, escolha o **Adicionar nova referência** botão. Para obter mais informações sobre o **referências** caixa de diálogo, consulte [Adicionando referências](../ide/adding-references-in-visual-cpp-projects.md).  
  
3.  O **Adicionar referência** caixa de diálogo lista as bibliotecas que você pode fazer referência. O **projetos** guia lista os projetos na solução atual e todas as bibliotecas que eles contêm. Sobre o **projetos** guia, marque a caixa de seleção ao lado **MathLibrary**, e, em seguida, escolha o **OK** botão.  
  
4.  É necessário que as definições no arquivo MathLibrary.h para chamar as funções de DLLs de seu aplicativo. Você pode copiar o arquivo de cabeçalho no projeto de aplicativo do cliente, mas que pode levar a alterações em uma cópia que não são refletidas no outro. Para evitar esse problema ao fazer referência a arquivos de cabeçalho da DLL, você pode alterar o caminho de diretórios incluídos em seu projeto para incluir o cabeçalho original. Para fazer isso, abra o **páginas de propriedade** caixa de diálogo para o **MathClient** projeto. No painel esquerdo, expanda **Propriedades de configuração**, **C\/C\+\+** nó e selecione **geral**. No painel central, selecione o controle de lista suspensa ao lado de **diretórios de inclusão adicionais** caixa de edição e, em seguida, escolha **\< editar... \>**. Selecione o painel superior do **diretórios de inclusão adicionais** caixa de diálogo para habilitar um controle de edição. No controle de edição, especifique o caminho para o local do **MathLibrary.h** arquivo de cabeçalho. Como pode ser difícil digitar o caminho completo, você pode usar o controle de navegação \(**...**\) no final da caixa de edição para exibir um **Selecionar diretório** caixa de diálogo. Na caixa de diálogo subir um nível de pasta para o **MathLibraryAndClient** pasta, selecione o **MathLibrary** pasta e, em seguida, escolha o **Selecionar pasta** botão. Depois de inserir o caminho para o arquivo de cabeçalho no **diretórios de inclusão adicionais** caixa de diálogo, escolha o **OK** botão Voltar para o **páginas de propriedade** caixa de diálogo caixa e, em seguida, escolha o **OK** botão para salvar suas alterações.  
  
5.  Agora você pode incluir o **MathLibrary.h** arquivo e usar o **funções** classe em seu aplicativo cliente. Substitua o conteúdo do **MathClient.cpp** usando o seguinte código:  
  
    ```cpp  
    // MathClient.cpp : Defines the entry point for the console application.  
    // Compile by using: cl /EHsc /link MathLibrary.lib MathClient.cpp  
  
    #include "stdafx.h"  
    #include <iostream>  
    #include "MathLibrary.h"  
  
    using namespace std;  
  
    int main()  
    {  
        double a = 7.4;  
        int b = 99;  
  
        cout << "a + b = " <<  
            MathLibrary::Functions::Add(a, b) << endl;  
        cout << "a * b = " <<  
            MathLibrary::Functions::Multiply(a, b) << endl;  
        cout << "a + (a * b) = " <<  
            MathLibrary::Functions::AddMultiply(a, b) << endl;  
  
        return 0;  
    }  
    ```  
  
6.  Compilar o aplicativo escolhendo **criar**, **Build Solution** na barra de menus. A janela de saída no Visual Studio pode conter algo assim:  
  
    ```Output  
    1 >---compilação iniciada: projeto: MathLibrary, configuração: Debug Win32---1 > 1 MathLibrary.cpp > c:\users\username\documents\visual studio 2015\Projects\MathLibraryAndClient\Debug\MathLibrary.dll 2 -> MathLibrary.vcxproj >---compilação iniciada: projeto: MathClient, configuração: Debug Win32---2 > Stdafx 2 > MathClient.cpp 2 > MathClient.vcxproj -> c:\users\username\documents\visual studio 2015\Projects\MathLibraryAndClient\Debug\MathClient.exe === criar: 2 foi bem-sucedido, 0 falhou , 0 atualizadas, 0 ignorado ===  
  
    ```  
  
     Parabéns, você criou um aplicativo que chama as funções em uma DLL. Em seguida, você executará o aplicativo para ver o que ele faz.  
  
### Para executar o aplicativo  
  
1.  Desde que seja possível executar uma DLL, verifique se **MathClient** está selecionado como o projeto padrão. Esse é o projeto Visual Studio é executado quando você escolhe o **Iniciar depuração** ou **Start Without Debugging** comandos. Em **Solution Explorer**, selecione **MathClient**, e, em seguida, na barra de menus, escolha **projeto**, **Definir como projeto de inicialização**.  
  
2.  Para executar o **MathClient** projeto, na barra de menus, escolha **Depurar**, **Start Without Debugging**. O Visual Studio abre uma janela de comando para o programa seja executado. A saída deve ter esta aparência:  
  
    ```Output  
    um + b = 106,4 um * b = 732,6 um + (um * b) = 740 pressione qualquer tecla para continuar. . .  
    ```  
  
     Você pode pressionar qualquer tecla para fechar a janela de comando.  
  
     Agora que você criou uma DLL e um aplicativo cliente, você pode experimentar. Tente definir pontos de interrupção no código do aplicativo cliente ou na biblioteca e executar o aplicativo no depurador. Adicionar outros membros à classe de funções ou adicionar uma nova classe.  
  
## Consulte também  
 [Tour guiado do Visual C\+\+](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)   
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)   
 [Implantando aplicativos da área de trabalho](../Topic/Deploying%20Native%20Desktop%20Applications%20\(Visual%20C++\).md)   
 [Instruções passo a passo: implantando o programa \(C\+\+\)](../ide/walkthrough-deploying-your-program-cpp.md)   
 [Chamando funções DLL a partir de aplicativos Visual Basic](../build/calling-dll-functions-from-visual-basic-applications.md)