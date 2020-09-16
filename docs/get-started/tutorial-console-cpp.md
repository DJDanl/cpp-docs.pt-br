---
title: Criar uma calculadora de console em C++
description: Criar um aplicativo de console Olá, Mundo e um aplicativo de calculadora no Visual C++
ms.custom: mvc
ms.date: 08/19/2019
ms.topic: tutorial
ms.devlang: cpp
ms.assetid: 45138d70-719d-42dc-90d7-1d0ca31a2f54
ms.openlocfilehash: 14e1e18da5cdabae5366d4ba97a2260d5e99f076
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90685315"
---
# <a name="create-a-console-calculator-in-c"></a>Criar uma calculadora de console em C++

::: moniker range=">=vs-2019"

O ponto de partida usual para um programador de C++ é um aplicativo "Olá, mundo!" executado na linha de comando. Isso é o que você criará primeiro no Visual Studio neste artigo e, em seguida, passaremos para algo mais desafiador: um aplicativo de calculadora.

## <a name="prerequisites"></a>Pré-requisitos

- Tenha o Visual Studio com o **desenvolvimento de desktop com** carga de trabalho do C++ instalada e em execução no seu computador. Se ele ainda não estiver instalado, confira [Instalar suporte para C++ no Visual Studio](../build/vscpp-step-0-installation.md).

## <a name="create-your-app-project"></a>Criar seu projeto de aplicativo

O Visual Studio usa os *projetos* para organizar o código em um aplicativo e as *soluções* para organizar seus projetos. Um projeto contém todas as opções, configurações e regras usadas para criar seus aplicativos. Ele também gerencia a relação entre todos os arquivos de projeto e todos os arquivos externos. Para criar seu aplicativo, primeiro, crie um novo projeto e uma nova solução.

1. Se tiver começado a usar o Visual Studio, você verá a caixa de diálogo do Visual Studio 2019. Escolha **Criar um novo projeto** para começar.

   ![A caixa de diálogo inicial do Visual Studio 2019](./media/calc-vs2019-initial-dialog.png "A caixa de diálogo inicial do Visual Studio 2019")

   Caso contrário, na barra de menus no Visual Studio, escolha **arquivo**  >  **novo**  >  **projeto**. A janela **Criar um novo projeto** é aberta.

1. Na lista de modelos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar**.

   ![Escolher o modelo de aplicativo de console](./media/calc-vs2019-choose-console-app.png "Escolher o modelo de aplicativo de console")

   > [!Important]
   > É preciso que você escolha a versão do C++ do modelo do **Aplicativo de Console**. Ele tem as marcas **C++**, **Windows** e **Console**, enquanto o ícone tem "++" no canto.

1. Na caixa de diálogo **Configurar novo projeto**, selecione a caixa de edição **Nome do projeto**, dê ao novo projeto o nome *CalculatorTutorial* e, em seguida, escolha **Criar**.

   ![Nomeie seu projeto na caixa de diálogo Configurar seu novo projeto](./media/calc-vs2019-name-your-project.png "Nomeie seu projeto na caixa de diálogo Configurar seu novo projeto")

   Um aplicativo de console do Windows C++ vazio é criado. Os aplicativos de console usam uma janela de console do Windows para exibir a saída e aceitar a entrada do usuário. No Visual Studio, uma janela do editor é aberta e mostra o código gerado:

    ```cpp
    // CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
    //

    #include <iostream>

    int main()
    {
        std::cout << "Hello World!\n";
    }

    // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
    // Debug program: F5 or Debug > Start Debugging menu

    // Tips for Getting Started:
    //   1. Use the Solution Explorer window to add/manage files
    //   2. Use the Team Explorer window to connect to source control
    //   3. Use the Output window to see build output and other messages
    //   4. Use the Error List window to view errors
    //   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
    //   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
    ```

## <a name="verify-that-your-new-app-builds-and-runs"></a>Verificar se o novo aplicativo compila e executa

O modelo para um novo aplicativo de console do Windows cria um aplicativo simples "Olá, Mundo" em C++. Neste ponto, você pode ver como o Visual Studio compila e executa os aplicativos que você cria diretamente no IDE.

1. Para compilar o projeto, escolha **Compilar Solução** no menu **Compilar**. A janela de **Saída** mostra os resultados do processo de build.

   ![Captura de tela do Visual Studio 2019 com a janela de saída mostrando o resultado do processo de compilação.](./media/calc-vs2019-build-your-project.png "Compilar o projeto")

1. Para executar o código, na barra de menus, escolha **Depurar**, **Iniciar sem depuração**.

   ![Captura de tela do console de depuração do Visual Studio 2019 Microsoft Visual Studio mostrando que o código foi executado com êxito.](./media/calc-vs2019-hello-world-console.png "Iniciar o projeto")

   Uma janela do console é aberta e, em seguida, executa seu aplicativo. Quando você inicia um aplicativo de console no Visual Studio, ele é executado em seu código e, em seguida, imprime "Pressione qualquer tecla para fechar esta janela. . ." para dar a oportunidade de ver a saída. Parabéns! Você criou seu primeiro aplicativo de console "Olá, mundo!" no Visual Studio!

1. Pressione uma tecla para ignorar a janela do console e retornar ao Visual Studio.

Agora você tem as ferramentas para compilar e executar seu aplicativo após cada alteração para verificar se o código ainda funciona conforme o esperado. Posteriormente, mostraremos como depurá-lo se ele não funcionar bem.

## <a name="edit-the-code"></a>Editar o código

Agora vamos examinar o código neste modelo em um aplicativo de calculadora.

1. No arquivo *CalculatorTutorial.cpp*, edite o código para corresponder a este exemplo:

    ```cpp
    // CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
    //

    #include <iostream>

    using namespace std;

    int main()
    {
        cout << "Calculator Console Application" << endl << endl;
        cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b"
            << endl;
        return 0;
    }

    // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
    // Debug program: F5 or Debug > Start Debugging menu
    // Tips for Getting Started:
    //   1. Use the Solution Explorer window to add/manage files
    //   2. Use the Team Explorer window to connect to source control
    //   3. Use the Output window to see build output and other messages
    //   4. Use the Error List window to view errors
    //   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
    //   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
    ```

   > Noções básicas sobre o código:
   >
   > - As instruções `#include` permitem que você consulte a código localizado em outros arquivos. Às vezes, você pode ver um nome de arquivo entre colchetes angulares ( **\<\>** ); outras vezes, está entre aspas (**""**). Em geral, os colchetes angulares são usados ao fazer referência à biblioteca padrão C++, enquanto as aspas são usadas para outros arquivos.
   > - A linha `using namespace std;` informa ao compilador para esperar que coisas da Biblioteca Padrão C++ sejam usadas nesse arquivo. Sem essa linha, cada palavra-chave da biblioteca precisaria ser precedida por um `std::` para indicar seu escopo. Por exemplo, sem essa linha, cada referência a `cout` precisaria ser escrito como `std::cout`. A **`using`** instrução é adicionada para tornar o código mais limpo.
   > - A palavra-chave `cout` é usada para imprimir a saída padrão em C++. O **\<\<** operador informa ao compilador para enviar o que estiver à direita dele para a saída padrão.
   > - A palavra-chave **endl** é como a tecla Enter; encerra a linha e move o cursor para a próxima linha. É uma melhor prática para colocar um `\n` dentro da cadeia de caracteres (contido por "") para fazer a mesma coisa, uma vez que `endl` sempre libera o buffer e pode prejudicar o desempenho do programa, mas já que esse é um aplicativo muito pequeno, `endl` é usado em vez disso para melhor legibilidade.
   > - Todas as instruções C++ devem terminar com ponto e vírgula e todos os aplicativos C++ devem conter uma função `main()`. Essa função é o que o programa é executado no início. Todo o código deve estar acessível de `main()` para ser usado.

1. Para salvar o arquivo, insira **Ctrl+S** ou escolha o ícone **Salvar** ao lado da parte superior do IDE, o ícone de disquete na barra de ferramentas na barra de menus.

1. Para executar o aplicativo, pressione **CTRL+F5** ou vá para o menu **Depurar** e escolha **Iniciar Sem Depuração**. Você deve ver uma janela do console em exibição com o texto especificado no código.

1. Feche a janela do console ao terminar.

## <a name="add-code-to-do-some-math"></a>Adicionar código para fazer alguns cálculos matemáticos

É hora de adicionar alguma lógica de matemática.

### <a name="to-add-a-calculator-class"></a>Para adicionar uma classe de Calculadora

1. Vá para o menu **Projeto** e escolha **Adicionar Classe**. Na caixa de edição **Nome de Classe**, digite *Calculadora*. Selecione **OK**. Dois novos arquivos são adicionados ao seu projeto. Para salvar todos os arquivos alterados de uma vez, pressione **Ctrl+Shift+S**. É um atalho de teclado para **arquivo**  >  **salvar tudo**. Também há um botão de barra de ferramentas para **Salvar Tudo**, um ícone de dois disquetes, encontrado ao lado do botão **Salvar**. Em geral, é uma boa prática executar **Salvar Tudo** com frequência, para que você não perca nenhum arquivo ao salvar.

   ![Captura de tela da caixa de diálogo Adicionar classe com a calculadora digitada na caixa de texto nome da classe.](./media/calc-vs2019-create-calculator-class.png "Criar a classe de calculadora")

   Uma classe é como um blueprint para um objeto que faz algo. Nesse caso, definimos uma calculadora e como ela deve funcionar. O assistente **Adicionar Classe** usado acima criou arquivos .h e .cpp que têm o mesmo nome que a classe. Você pode ver uma lista completa dos arquivos de projeto na janela **Gerenciador de soluções** , visível no lado do IDE. Se a janela não estiver visível, você poderá abri-la na barra de menus: escolha **Exibir**  >  **Gerenciador de soluções**.

   ![Captura de tela da janela Gerenciador de Soluções do Visual Studio 2019 exibindo o projeto do tutorial da calculadora.](./media/calc-vs2019-solution-explorer.png "Gerenciador de Soluções")

   Agora você deve ter três guias abertas no editor: *CalculatorTutorial. cpp*, *Calculator. h*e *Calculator. cpp*. Se você fechar acidentalmente um deles, poderá reabri-lo clicando duas vezes nele na janela **Gerenciador de soluções** .

1. Em **Calculator.h**, remova as linhas `Calculator();` e `~Calculator();` que foram geradas, já que você não precisa delas aqui. Em seguida, adicione a seguinte linha de código para que o arquivo agora tenha esta aparência:

    ```cpp
    #pragma once
    class Calculator
    {
    public:
        double Calculate(double x, char oper, double y);
    };
    ```

   > Compreender o código
   >
   > - A linha que você adicionou declara uma nova função chamada `Calculate`, que usaremos para executar operações matemáticas para adição, subtração, multiplicação e divisão.
   > - O código C++ é organizado em arquivos de *cabeçalho* (.h) e de *origem* (.cpp). Várias outras extensões de arquivo têm suporte pelos vários compiladores, mas estes são os principais conhecer. Funções e variáveis normalmente são *declaradas*, ou seja, recebem um nome e um tipo, nos arquivos de cabeçalho, e *implementadas* ou recebem uma definição nos arquivos de origem. Para acessar código definido em outro arquivo, você pode usar `#include "filename.h"`, em que 'filename.h' é o nome do arquivo que declara as variáveis ou funções que você deseja usar.
   > - As duas linhas que você excluiu declararam um *construtor* e um *destruidor* para a classe. Para uma classe simples como essa, o compilador as cria para você e seus usos estão além do escopo deste tutorial.
   > - É uma boa prática organizar seu código em arquivos diferentes com base no que ele faz, de modo que seja fácil encontrar o código de que você precisa mais tarde. Em nosso caso, definimos a classe `Calculator` separadamente do arquivo que contém a função `main()`, mas podemos planejar fazer referência à classe `Calculator` em `main()`.

1. Você verá um rabisco verde aparecer sob `Calculate`. Ocorre porque ainda não definimos a função `Calculate` no arquivo .cpp. Passe o mouse sobre a palavra, clique na lâmpada (neste caso, uma chave de fenda) que aparece em pop-up e escolha **Criar uma definição de 'Calculate' em Calculator.cpp**.

   ![Captura de tela do Visual Studio 2019 mostrando a opção Criar definição de calcular na calculadora C P P realçada.](./media/calc-vs2019-create-definition.png "Criar definição de Calculate")

   Um pop-up será exibido, possibilitando uma espiada na alteração de código que foi feita em outro arquivo. O código foi adicionado ao *Calculator.cpp*.

   ![Pop-up com definição de Calculate](./media/calc-vs2019-pop-up-definition.png "Pop-up com definição de Calculate")

   Atualmente, retorna apenas 0,0. Vamos mudar isso. Pressione **Esc** para fechar o pop-up.

1. Alterne para o arquivo *Calculator.cpp* na janela do editor. Remova as seções `Calculator()` e `~Calculator()` (como fez no arquivo .h) e adicione o seguinte código a `Calculate()`:

    ```cpp
    #include "Calculator.h"

    double Calculator::Calculate(double x, char oper, double y)
    {
        switch(oper)
        {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            default:
                return 0.0;
        }
    }
    ```

   > Compreender o código
   >
   > - A função `Calculate` consome um número, um operador e um segundo número e, em seguida, executa a operação solicitada nos números.
   > - A instrução de opção verifica que operador foi fornecido e somente executa o caso que corresponde a essa operação. O padrão: caso é uma contingência se o usuário digita um operador que não é aceito, de modo que o programa não seja interrompido. Em geral, é melhor manipular uma entrada de usuário inválida de uma maneira mais elegante, mas isso está além do escopo deste tutorial.
   > - A **`double`** palavra-chave denota um tipo de número que dá suporte a decimais. Dessa forma, a calculadora pode lidar com matemática decimal e de inteiros. A `Calculate` função é necessária para sempre retornar um número como **`double`** esse, devido à parte inicial do código (isso denota o tipo de retorno da função), que é por isso que retornamos 0,0 mesmo no caso padrão.
   > - O arquivo .h declara a função *protótipo*, que informa ao compilador antecipadamente quais parâmetros são necessários e que tipo de retorno esperar dele. O arquivo .cpp tem todos os detalhes de implementação da função.

Se você compilar e executar o código novamente neste ponto, ele ainda será encerrado depois de perguntar qual operação executar. Em seguida, você modificará a função `main` para fazer alguns cálculos.

### <a name="to-call-the-calculator-class-member-functions"></a>Para chamar funções de membro da classe Calculadora

1. Agora vamos atualizar a função `main` em *CalculatorTutorial.cpp*:

    ```cpp
    // CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
    //

    #include <iostream>
    #include "Calculator.h"

    using namespace std;

    int main()
    {
        double x = 0.0;
        double y = 0.0;
        double result = 0.0;
        char oper = '+';

        cout << "Calculator Console Application" << endl << endl;
        cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b"
             << endl;

        Calculator c;
        while (true)
        {
            cin >> x >> oper >> y;
            result = c.Calculate(x, oper, y);
            cout << "Result is: " << result << endl;
        }

        return 0;
    }
    ```

   > Compreender o código
   >
   > - Uma vez que os programas C++ sempre começam com a função `main()`, precisamos chamar o outro código daí, portanto, uma instrução `#include` é necessária.
   > - Algumas variáveis iniciais `x`, `y`, `oper` e `result` são declaradas para armazenar o primeiro número, o segundo número, o operador e o resultado final, respectivamente. É sempre uma boa prática fornecer alguns valores iniciais para evitar um comportamento indefinido, o que é feito aqui.
   > - A linha `Calculator c;` declara um objeto chamado 'c' como uma instância da classe `Calculator`. A classe em si é apenas o blueprint para como as calculadoras funcionam; o objeto é a calculadora específica que faz os cálculos.
   > - A instrução `while (true)` é um loop. O código dentro do loop continua sendo executado repetidamente enquanto a condição em `()` se aplicar. Como a condição é simplesmente listada como **`true`** , ela é sempre verdadeira, portanto, o loop é executado para sempre. Para fechar o programa, o usuário deve fechar manualmente a janela do console. Caso contrário, o programa sempre esperará a nova entrada.
   > - A palavra-chave `cin` é usada para aceitar a entrada do usuário. Esse fluxo de entrada é inteligente o suficiente para processar uma linha de texto inserida na janela do console e colocá-la dentro de cada uma das variáveis listadas, em ordem, supondo que a entrada do usuário corresponda à especificação necessária. Você pode modificar essa linha para aceitar diferentes tipos de entrada, por exemplo, mais de dois números, embora a função `Calculate()` também precise ser atualizada para lidar com isso.
   > - A expressão `c.Calculate(x, oper, y);` chama a função `Calculate` definida anteriormente e fornece os valores de entrada inseridos. A função retorna um número que é armazenado em `result`.
   > - Por fim, `result` é impresso no console para que o usuário veja o resultado do cálculo.

### <a name="build-and-test-the-code-again"></a>Compilar e testar o código novamente

Agora é hora de testar o programa novamente para verificar se que tudo está funcionando bem.

1. Pressione **Ctrl+F5** para recompilar e iniciar o aplicativo.

1. Insira `5 + 5` e pressione **Enter**. Verifique se o resultado será 10.

   ![Captura de tela do console de depuração do Visual Studio 2019 Microsoft Visual Studio mostrando o resultado correto de 5 + 5.](./media/calc-vs2019-five-plus-five.png "O resultado de 5 + 5")

## <a name="debug-the-app"></a>Depurar o aplicativo

Uma vez que o usuário é livre para digitar qualquer coisa na janela do console, vamos garantir que a calculadora lide com alguma entrada conforme o esperado. Em vez de executar o programa, vamos depurá-lo para que seja possível inspecionar o que ele está fazendo em detalhes, passo a passo.

### <a name="to-run-the-app-in-the-debugger"></a>Para executar o aplicativo no depurador

1. Defina um ponto de interrupção na linha `result = c.Calculate(x, oper, y);`, logo após o usuário ter sido solicitado a inserir a entrada. Para definir um ponto de interrupção, clique Para fazer isso, clique ao lado da linha na barra vertical cinza ao longo da borda esquerda da janela do editor. Um ponto vermelho é exibido.

   ![Captura de tela do Visual Studio 2019 mostrando o Red Dot que representa um ponto de interrupção.](./media/calc-vs2019-set-breakpoint.png "Definir um ponto de interrupção")

   Agora quando depuramos o programa, ele sempre pausa a execução nessa linha. Já temos uma ideia superficial de que o programa funciona para casos simples. Como não queremos pausar a execução toda vez, vamos tornar o ponto de interrupção condicional.

1. Clique com o botão direito do mouse no ponto vermelho que representa o ponto de interrupção e escolha **Condições**. Na caixa de edição para a condição, insira `(y == 0) && (oper == '/')`. Escolha o botão **OK** quando tiver terminado. A condição é salva automaticamente.

   ![Captura de tela do Visual Studio 2019 mostrando a seção Configurações de ponto de interrupção e uma condição adicionada ao valor é verdadeiro.](./media/calc-vs2019-conditional-breakpoint.png "Definir um ponto de interrupção condicional")

   Agora vamos pausar a execução no ponto de interrupção especificamente se você tentar uma divisão por 0.

1. Para depurar o programa, pressione **F5** ou escolha o botão da barra de ferramentas **Depurador Local do Windows** que tem um ícone de seta verde. Em seu aplicativo de console, se você digitar algo como "0-5", o programa se comportará normalmente e continuará em execução. No entanto, se você digitar "10 / 0", ele fará uma pausa no ponto de interrupção. Você pode até mesmo colocar qualquer número de espaços entre o operador e os números. `cin` é inteligente o suficiente para analisar a entrada de modo adequado.

   ![Captura de tela do Visual estúdios 2019 mostrando que o programa está em pausa no ponto de interrupção condicional.](./media/calc-vs2019-debug-breakpoint.png "Pausar no ponto de interrupção condicional")

### <a name="useful-windows-in-the-debugger"></a>Janelas úteis no depurador

Sempre que você depura seu código, pode perceber que algumas novas janelas aparecem. Essas janelas podem ajudar a sua experiência de depuração. Dê uma olhada na janela **Autos**. A janela **Autos** mostra os valores atuais das variáveis usadas pelo menos três linhas antes e até a linha atual. Para ver todas as variáveis dessa função, alterne para a janela **Locais**. Na verdade, você pode modificar os valores dessas variáveis enquanto depura para ver que efeito elas teriam sobre o programa. Neste caso, podemos deixá-las de lado.

   ![Captura de tela da janela locais no Visual Studio 2019.](./media/calc-vs2019-debug-locals.png "A janela locais")

Também é possível apenas focalizar variáveis no código em si para ver seus valores atuais em que a execução está em pausa momento. Verifique se a janela do editor está em foco clicando nela primeiro.

   ![Captura de tela do Visual Studio 2019 mostrando a dica de ferramenta que aparece exibindo o valor da variável.](./media/calc-vs2019-hover-tooltip.png "Focalizar para exibir valores de variáveis atuais")

### <a name="to-continue-debugging"></a>Para continuar a depuração

1. A linha amarela à esquerda mostra o ponto atual de execução. A linha atual que chama `Calculate`, assim, pressione **F11** para **Depurar** a função. Você se encontrará no corpo da função `Calculate`. Atenção ao **Depurar**; se fizer isso muitas vezes, poderá perder muito tempo. Ela entra em qualquer código que você usa na linha em que você está, incluindo funções de biblioteca padrão.

1. Agora que o ponto de execução está no início da função `Calculate`, pressione **F10** para ir para a próxima linha na execução do programa. **F10** também é conhecido como **Depuração Parcial**. Você pode usar **Depuração Parcial** para mover de uma linha para outra, sem aprofundar-se nos detalhes do que está ocorrendo em cada parte da linha. Em geral, você deve usar **Depuração Parcial** em vez de **Depurar**, a menos que queira aprofundar-se no código que está sendo chamado de outro lugar (como você fez para alcançar o corpo de `Calculate`).

1. Continue usando **F10** para realizar a **Depuração Parcial** de cada linha até que você voltar para a função `main()` no outro arquivo e pare na linha `cout`.

   Parece que o programa está fazendo o que é esperado: ele usa o primeiro número e o divide pelo segundo. Na linha `cout`, focalize a variável `result` ou dê uma olhada `result` na janela **Autos**. Você verá que seu valor está listado como "inf", o que não parece correto, então vamos corrigi-lo. A linha `cout` somente gera qualquer valor que esteja armazenado em `result`, portanto, quando você avança mais uma linha usando **F10**, a janela do console exibe:

   ![Captura de tela do console de depuração do Microsoft Visual Studio do Visual Studio 2019 mostrando o resultado da divisão por zero.](./media/calc-vs2019-divide-by-zero-fail.png "O resultado da divisão por zero")

   Esse resultado acontece porque a divisão por zero é indefinida, portanto, o programa não tem uma resposta numérica para a operação solicitada.

### <a name="to-fix-the-divide-by-zero-error"></a>Para consertar o erro de "dividir por zero"

Vamos tratar da divisão por zero de modo mais simples para que um usuário possa entender o problema.

1. Faça as seguintes alterações a *CalculatorTutorial.cpp*. (Você pode deixar o programa em execução durante a edição, graças a um recurso do depurador chamado **Editar e Continuar**):

    ```cpp
    // CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
    //

    #include <iostream>
    #include "Calculator.h"

    using namespace std;

    int main()
    {
        double x = 0.0;
        double y = 0.0;
        double result = 0.0;
        char oper = '+';

        cout << "Calculator Console Application" << endl << endl;
        cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b" << endl;

        Calculator c;
        while (true)
        {
            cin  >> x  >> oper  >> y;
            if (oper == '/' && y == 0)
            {
                cout << "Division by 0 exception" << endl;
                continue;
            }
            else
            {
                result = c.Calculate(x, oper, y);
            }
            cout << "Result is: " << result << endl;
        }

        return 0;
    }
    ```

1. Agora pressione **F5** uma vez. A execução do programa continua até ele precisar pausar para pedir entrada do usuário. Insira `10 / 0` novamente. Agora, é impressa uma mensagem mais útil. O usuário é solicitado a fornecer mais entradas e o programa continua em execução normalmente.

   ![Captura de tela do console de depuração do Microsoft Visual Studio do Visual Studio 2019 mostrando o resultado final após as alterações.](./media/calc-vs2019-final-verification.png "O resultado final após as alterações")

   > [!Note]
   > Quando você edita o código no modo de depuração, há um risco de o código se tornar obsoleto. Isso acontece quando o depurador ainda está executando seu código antigo e não ainda o atualizou com suas alterações. O depurador abre em pop-up uma caixa de diálogo para informá-lo quando isso acontece. Às vezes, pode ser necessário pressionar **F5** para atualizar o código que está sendo executado. Em particular, se você fizer uma alteração dentro de uma função enquanto o ponto de execução está dentro daquela função, precisará sair da função e voltar para ela para obter o código atualizado. Se isso não funcionar por alguma razão e você vir uma mensagem de erro, você poderá interromper a depuração clicando no quadrado vermelho na barra de ferramentas abaixo dos menus na parte superior do IDE e iniciar a depuração novamente inserindo **F5** ou escolhendo a seta " reproduzir" verde ao lado do botão Parar na barra de ferramentas.

   > Noções básicas sobre os atalhos de Executar e Depurar
   >
   > - **F5** (ou **Depurar** > **Iniciar Depuração**) iniciará uma sessão de depuração se uma ainda não estiver ativa e executará o programa até atingir um ponto de interrupção ou o programa precisar de entrada do usuário. Se nenhuma entrada do usuário for necessária e nenhum ponto de interrupção estiver disponível para ser atingido, o programa será encerrado e a janela do console fechará mesmo quando o programa for encerrado. Se você tiver algo parecido com um programa "Olá, Mundo" para ser executado, use **CTRL+F5** ou defina um ponto de interrupção antes de inserir **F5** para manter a janela aberta.
   > - **CTRL + F5** (ou **Depurar** > **Iniciar sem Depuração**) executa o aplicativo sem entrar no modo de depuração. Isso é um pouco mais rápido do que a depuração e a janela do console permaneça aberta depois de o programa terminar a execução.
   > - **F10** (conhecido como **Depuração Parcial**) permite que você itere pelo código linha por linha e visualize como o código é executado e quais valores de variáveis estão em cada etapa de execução.
   > - **F11** (conhecido como **Depurar**) funciona da mesma forma que **Depuração Parcial**, exceto que depura todas as funções chamadas na linha de execução. Por exemplo, se a linha que está sendo executada chamar uma função, pressionar **F11** moverá o ponteiro para o corpo da função, de modo que você possa seguir o código da função que está em execução antes de voltar para a linha em que começou. Pressionar **F10** faz a depuração parcial da chamada de função e apenas se move para a próxima linha; a chamada de função ainda acontece, mas o programa não pausa para mostrar o você está fazendo.

### <a name="close-the-app"></a>Feche o aplicativo

- Se ele ainda estiver em execução, feche a janela de console para o aplicativo de calculadora.

## <a name="the-finished-app"></a>O aplicativo finalizado

Parabéns! Você concluiu o código para o aplicativo de calculadora e o compilou e depurou no Visual Studio.

## <a name="next-steps"></a>Próximas etapas

[Saiba mais sobre o Visual Studio para C++](https://devblogs.microsoft.com/cppblog/getting-started-with-visual-studio-for-c-and-cpp-development/)

::: moniker-end

::: moniker range="<vs-2019"

O ponto de partida usual para um programador de C++ é um aplicativo "Olá, mundo!" executado na linha de comando. É isso que você criará no Visual Studio neste artigo e, em seguida, passaremos para algo mais desafiador: um aplicativo de calculadora.

## <a name="prerequisites"></a>Pré-requisitos

- Tenha o Visual Studio com o **desenvolvimento de desktop com** carga de trabalho do C++ instalada e em execução no seu computador. Se ele ainda não estiver instalado, confira [Instalar suporte para C++ no Visual Studio](../build/vscpp-step-0-installation.md).

## <a name="create-your-app-project"></a>Criar seu projeto de aplicativo

O Visual Studio usa os *projetos* para organizar o código em um aplicativo e as *soluções* para organizar seus projetos. Um projeto contém todas as opções, configurações e regras usadas para criar seus aplicativos. Ele também gerencia a relação entre todos os arquivos de projeto e todos os arquivos externos. Para criar seu aplicativo, primeiro, crie um novo projeto e uma nova solução.

1. Na barra de menus no Visual Studio, escolha **arquivo**  >  **novo**  >  **projeto**. A janela **Novo Projeto** é aberta.

2. Na barra lateral esquerda, verifique se **Visual C++** está selecionado. No centro, escolha **Aplicativo de Console do Windows**.

3. Na caixa de edição **Nome** na parte inferior de edição, dê um nome ao novo projeto *CalculatorTutorial* e, em seguida, escolha **OK**.

   ![A caixa de diálogo novo projeto](./media/calculator-new-project-dialog.png "A caixa de diálogo novo projeto")

   Um aplicativo de console do Windows C++ vazio é criado. Os aplicativos de console usam uma janela de console do Windows para exibir a saída e aceitar a entrada do usuário. No Visual Studio, uma janela do editor é aberta e mostra o código gerado:

    ```cpp
    // CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
    //

    #include "pch.h"
    #include <iostream>

    int main()
    {
        std::cout << "Hello World!\n";
    }

    // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
    // Debug program: F5 or Debug > Start Debugging menu

    // Tips for Getting Started:
    //   1. Use the Solution Explorer window to add/manage files
    //   2. Use the Team Explorer window to connect to source control
    //   3. Use the Output window to see build output and other messages
    //   4. Use the Error List window to view errors
    //   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
    //   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
    ```

## <a name="verify-that-your-new-app-builds-and-runs"></a>Verificar se o novo aplicativo compila e executa

O modelo para um novo aplicativo de console do Windows cria um aplicativo simples "Olá, Mundo" em C++. Neste ponto, você pode ver como o Visual Studio compila e executa os aplicativos que você cria diretamente no IDE.

1. Para compilar o projeto, escolha **Compilar Solução** no menu **Compilar**. A janela de **Saída** mostra os resultados do processo de build.

   ![Captura de tela do Visual Studio com a janela de saída mostrando o resultado do processo de compilação.](./media/calculator-initial-build-output.png "Compilar o projeto")

1. Para executar o código, na barra de menus, escolha **Depurar**, **Iniciar sem depuração**.

   ![Captura de tela da Microsoft Visual Studio console de depuração mostrando que o código foi executado com êxito.](./media/calculator-hello-world-console.png "Iniciar o projeto")

   Uma janela do console é aberta e, em seguida, executa seu aplicativo. Quando você inicia um aplicativo de console no Visual Studio, ele é executado em seu código e, em seguida, imprime "Pressione qualquer tecla para continuar. . ." para dar a oportunidade de ver a saída. Parabéns! Você criou seu primeiro aplicativo de console "Olá, mundo!" no Visual Studio!

1. Pressione uma tecla para ignorar a janela do console e retornar ao Visual Studio.

Agora você tem as ferramentas para compilar e executar seu aplicativo após cada alteração para verificar se o código ainda funciona conforme o esperado. Posteriormente, mostraremos como depurá-lo se ele não funcionar bem.

## <a name="edit-the-code"></a>Editar o código

Agora vamos examinar o código neste modelo em um aplicativo de calculadora.

1. No arquivo *CalculatorTutorial.cpp*, edite o código para corresponder a este exemplo:

    ```cpp
    // CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
    //

    #include "pch.h"
    #include <iostream>

    using namespace std;

    int main()
    {
        cout << "Calculator Console Application" << endl << endl;
        cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b"
            << endl;
        return 0;
    }

    // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
    // Debug program: F5 or Debug > Start Debugging menu
    // Tips for Getting Started:
    //   1. Use the Solution Explorer window to add/manage files
    //   2. Use the Team Explorer window to connect to source control
    //   3. Use the Output window to see build output and other messages
    //   4. Use the Error List window to view errors
    //   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
    //   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
    ```

   > Noções básicas sobre o código:
   >
   > - As instruções `#include` permitem que você consulte a código localizado em outros arquivos. Às vezes, você pode ver um nome de arquivo entre colchetes angulares ( **\<\>** ); outras vezes, está entre aspas (**""**). Em geral, os colchetes angulares são usados ao fazer referência à biblioteca padrão C++, enquanto as aspas são usadas para outros arquivos.
   > - A linha `#include "pch.h"` (ou, no Visual Studio 2017 e versões anteriores, `#include "stdafx.h"`) faz referência a algo conhecido como cabeçalho pré-compilado. Isso costuma ser usado por programadores profissionais para melhorar os tempos de compilação, mas estão além do escopo deste tutorial.
   > - A linha `using namespace std;` informa ao compilador para esperar que coisas da Biblioteca Padrão C++ sejam usadas nesse arquivo. Sem essa linha, cada palavra-chave da biblioteca precisaria ser precedida por um `std::` para indicar seu escopo. Por exemplo, sem essa linha, cada referência a `cout` precisaria ser escrito como `std::cout`. A **`using`** instrução é adicionada para tornar o código mais limpo.
   > - A palavra-chave `cout` é usada para imprimir a saída padrão em C++. O **\<\<** operador informa ao compilador para enviar o que estiver à direita dele para a saída padrão.
   > - A palavra-chave **endl** é como a tecla Enter; encerra a linha e move o cursor para a próxima linha. É uma melhor prática para colocar um `\n` dentro da cadeia de caracteres (contido por "") para fazer a mesma coisa, uma vez que `endl` sempre libera o buffer e pode prejudicar o desempenho do programa, mas já que esse é um aplicativo muito pequeno, `endl` é usado em vez disso para melhor legibilidade.
   > - Todas as instruções C++ devem terminar com ponto e vírgula e todos os aplicativos C++ devem conter uma função `main()`. Essa função é o que o programa é executado no início. Todo o código deve estar acessível de `main()` para ser usado.

1. Para salvar o arquivo, insira **Ctrl+S** ou escolha o ícone **Salvar** ao lado da parte superior do IDE, o ícone de disquete na barra de ferramentas na barra de menus.

1. Para executar o aplicativo, pressione **CTRL+F5** ou vá para o menu **Depurar** e escolha **Iniciar Sem Depuração**. Se você receber um pop-up com a mensagem **Este projeto está desatualizado**, você poderá selecionar **Não mostrar esta caixa de diálogo novamente** e, em seguida, escolher **Sim** para compilar seu aplicativo. Você deve ver uma janela do console em exibição com o texto especificado no código.

   ![Crie e inicie seu aplicativo](./media/calculator-first-launch.gif "Crie e inicie seu aplicativo")

1. Feche a janela do console ao terminar.

## <a name="add-code-to-do-some-math"></a>Adicionar código para fazer alguns cálculos matemáticos

É hora de adicionar alguma lógica de matemática.

### <a name="to-add-a-calculator-class"></a>Para adicionar uma classe de Calculadora

1. Vá para o menu **Projeto** e escolha **Adicionar Classe**. Na caixa de edição **Nome de Classe**, digite *Calculadora*. Selecione **OK**. Dois novos arquivos são adicionados ao seu projeto. Para salvar todos os arquivos alterados de uma vez, pressione **Ctrl+Shift+S**. É um atalho de teclado para **arquivo**  >  **salvar tudo**. Também há um botão de barra de ferramentas para **Salvar Tudo**, um ícone de dois disquetes, encontrado ao lado do botão **Salvar**. Em geral, é uma boa prática executar **Salvar Tudo** com frequência, para que você não perca nenhum arquivo ao salvar.

   ![Vídeo curto mostrando o usuário abrindo a caixa de diálogo Adicionar classe, digitando calculadora no campo nome da classe e selecionando O K.](./media/calculator-create-class.gif "Criar a classe de calculadora")

   Uma classe é como um blueprint para um objeto que faz algo. Nesse caso, definimos uma calculadora e como ela deve funcionar. O assistente **Adicionar Classe** usado acima criou arquivos .h e .cpp que têm o mesmo nome que a classe. Você pode ver uma lista completa dos arquivos de projeto na janela **Gerenciador de soluções** , visível no lado do IDE. Se a janela não estiver visível, você poderá abri-la na barra de menus: escolha **Exibir**  >  **Gerenciador de soluções**.

   ![Captura de tela da janela de Gerenciador de Soluções exibindo o projeto de tutorial da calculadora.](./media/calculator-solution-explorer.png "Gerenciador de Soluções")

   Agora você deve ter três guias abertas no editor: *CalculatorTutorial. cpp*, *Calculator. h*e *Calculator. cpp*. Se você fechar acidentalmente um deles, poderá reabri-lo clicando duas vezes nele na janela **Gerenciador de soluções** .

1. Em **Calculator.h**, remova as linhas `Calculator();` e `~Calculator();` que foram geradas, já que você não precisa delas aqui. Em seguida, adicione a seguinte linha de código para que o arquivo agora tenha esta aparência:

    ```cpp
    #pragma once
    class Calculator
    {
    public:
        double Calculate(double x, char oper, double y);
    };
    ```

   > Compreender o código
   >
   > - A linha que você adicionou declara uma nova função chamada `Calculate`, que usaremos para executar operações matemáticas para adição, subtração, multiplicação e divisão.
   > - O código C++ é organizado em arquivos de *cabeçalho* (.h) e de *origem* (.cpp). Várias outras extensões de arquivo têm suporte pelos vários compiladores, mas estes são os principais conhecer. Funções e variáveis normalmente são *declaradas*, ou seja, recebem um nome e um tipo, nos arquivos de cabeçalho, e *implementadas* ou recebem uma definição nos arquivos de origem. Para acessar código definido em outro arquivo, você pode usar `#include "filename.h"`, em que 'filename.h' é o nome do arquivo que declara as variáveis ou funções que você deseja usar.
   > - As duas linhas que você excluiu declararam um *construtor* e um *destruidor* para a classe. Para uma classe simples como essa, o compilador as cria para você e seus usos estão além do escopo deste tutorial.
   > - É uma boa prática organizar seu código em arquivos diferentes com base no que ele faz, de modo que seja fácil encontrar o código de que você precisa mais tarde. Em nosso caso, definimos a classe `Calculator` separadamente do arquivo que contém a função `main()`, mas podemos planejar fazer referência à classe `Calculator` em `main()`.

1. Você verá um rabisco verde aparecer sob `Calculate`. Ocorre porque ainda não definimos a função `Calculate` no arquivo .cpp. Passe o mouse sobre a palavra, clique na lâmpada que aparece em pop-up e escolha **criar uma definição de 'Calculate' em Calculator.cpp**. Um pop-up será exibido, possibilitando uma espiada na alteração de código que foi feita em outro arquivo. O código foi adicionado ao *Calculator.cpp*.

   ![Vídeo curto mostrando o usuário selecionando a opção Criar definição de calculado na calculadora C P P.](./media/calculator-create-definition.gif "Criar definição de Calculate")

   Atualmente, retorna apenas 0,0. Vamos mudar isso. Pressione **Esc** para fechar o pop-up.

1. Alterne para o arquivo *Calculator.cpp* na janela do editor. Remova as seções `Calculator()` e `~Calculator()` (como fez no arquivo .h) e adicione o seguinte código a `Calculate()`:

    ```cpp
    #include "pch.h"
    #include "Calculator.h"

    double Calculator::Calculate(double x, char oper, double y)
    {
        switch(oper)
        {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            default:
                return 0.0;
        }
    }
    ```

   > Compreender o código
   >
   > - A função `Calculate` consome um número, um operador e um segundo número e, em seguida, executa a operação solicitada nos números.
   > - A instrução de opção verifica que operador foi fornecido e somente executa o caso que corresponde a essa operação. O padrão: caso é uma contingência se o usuário digita um operador que não é aceito, de modo que o programa não seja interrompido. Em geral, é melhor manipular uma entrada de usuário inválida de uma maneira mais elegante, mas isso está além do escopo deste tutorial.
   > - A **`double`** palavra-chave denota um tipo de número que dá suporte a decimais. Dessa forma, a calculadora pode lidar com matemática decimal e de inteiros. A `Calculate` função é necessária para sempre retornar um número como **`double`** esse, devido à parte inicial do código (isso denota o tipo de retorno da função), que é por isso que retornamos 0,0 mesmo no caso padrão.
   > - O arquivo .h declara a função *protótipo*, que informa ao compilador antecipadamente quais parâmetros são necessários e que tipo de retorno esperar dele. O arquivo .cpp tem todos os detalhes de implementação da função.

Se você compilar e executar o código novamente neste ponto, ele ainda será encerrado depois de perguntar qual operação executar. Em seguida, você modificará a função `main` para fazer alguns cálculos.

### <a name="to-call-the-calculator-class-member-functions"></a>Para chamar funções de membro da classe Calculadora

1. Agora vamos atualizar a função `main` em *CalculatorTutorial.cpp*:

    ```cpp
    // CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
    //

    #include "pch.h"
    #include <iostream>
    #include "Calculator.h"

    using namespace std;

    int main()
    {
        double x = 0.0;
        double y = 0.0;
        double result = 0.0;
        char oper = '+';

        cout << "Calculator Console Application" << endl << endl;
        cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b"
             << endl;

        Calculator c;
        while (true)
        {
            cin >> x >> oper >> y;
            result = c.Calculate(x, oper, y);
            cout << "Result is: " << result << endl;
        }

        return 0;
    }
    ```

   > Compreender o código
   >
   > - Uma vez que os programas C++ sempre começam com a função `main()`, precisamos chamar o outro código daí, portanto, uma instrução `#include` é necessária.
   > - Algumas variáveis iniciais `x`, `y`, `oper` e `result` são declaradas para armazenar o primeiro número, o segundo número, o operador e o resultado final, respectivamente. É sempre uma boa prática fornecer alguns valores iniciais para evitar um comportamento indefinido, o que é feito aqui.
   > - A linha `Calculator c;` declara um objeto chamado 'c' como uma instância da classe `Calculator`. A classe em si é apenas o blueprint para como as calculadoras funcionam; o objeto é a calculadora específica que faz os cálculos.
   > - A instrução `while (true)` é um loop. O código dentro do loop continua sendo executado repetidamente enquanto a condição em `()` se aplicar. Como a condição é simplesmente listada como **`true`** , ela é sempre verdadeira, portanto, o loop é executado para sempre. Para fechar o programa, o usuário deve fechar manualmente a janela do console. Caso contrário, o programa sempre esperará a nova entrada.
   > - A palavra-chave `cin` é usada para aceitar a entrada do usuário. Esse fluxo de entrada é inteligente o suficiente para processar uma linha de texto inserida na janela do console e colocá-la dentro de cada uma das variáveis listadas, em ordem, supondo que a entrada do usuário corresponda à especificação necessária. Você pode modificar essa linha para aceitar diferentes tipos de entrada, por exemplo, mais de dois números, embora a função `Calculate()` também precise ser atualizada para lidar com isso.
   > - A expressão `c.Calculate(x, oper, y);` chama a função `Calculate` definida anteriormente e fornece os valores de entrada inseridos. A função retorna um número que é armazenado em `result`.
   > - Por fim, `result` é impresso no console para que o usuário veja o resultado do cálculo.

### <a name="build-and-test-the-code-again"></a>Compilar e testar o código novamente

Agora é hora de testar o programa novamente para verificar se que tudo está funcionando bem.

1. Pressione **Ctrl+F5** para recompilar e iniciar o aplicativo.

1. Insira `5 + 5` e pressione **Enter**. Verifique se o resultado será 10.

   ![Captura de tela da Microsoft Visual Studio console de depuração mostrando o resultado correto de 5 + 5.](./media/calculator-five-plus-five.png "O resultado de 5 + 5")

## <a name="debug-the-app"></a>Depurar o aplicativo

Uma vez que o usuário é livre para digitar qualquer coisa na janela do console, vamos garantir que a calculadora lide com alguma entrada conforme o esperado. Em vez de executar o programa, vamos depurá-lo para que seja possível inspecionar o que ele está fazendo em detalhes, passo a passo.

### <a name="to-run-the-app-in-the-debugger"></a>Para executar o aplicativo no depurador

1. Defina um ponto de interrupção na linha `result = c.Calculate(x, oper, y);`, logo após o usuário ter sido solicitado a inserir a entrada. Para definir um ponto de interrupção, clique Para fazer isso, clique ao lado da linha na barra vertical cinza ao longo da borda esquerda da janela do editor. Um ponto vermelho é exibido.

   ![Vídeo curto do Visual estúdios mostrando o usuário que está criando o ponto vermelho que representa um pontos de interrupção.](./media/calculator-set-breakpoint.gif "Definir um ponto de interrupção")

   Agora quando depuramos o programa, ele sempre pausa a execução nessa linha. Já temos uma ideia superficial de que o programa funciona para casos simples. Como não queremos pausar a execução toda vez, vamos tornar o ponto de interrupção condicional.

1. Clique com o botão direito do mouse no ponto vermelho que representa o ponto de interrupção e escolha **Condições**. Na caixa de edição para a condição, insira `(y == 0) && (oper == '/')`. Escolha o botão **OK** quando tiver terminado. A condição é salva automaticamente.

   ![Vídeo curto do Visual Studio 2019 mostrando o usuário abrindo a seção Configurações de ponto de interrupção e definindo um ponto de interrupção condicional.](./media/calculator-conditional-breakpoint.gif "Definir um ponto de interrupção condicional")

   Agora vamos pausar a execução no ponto de interrupção especificamente se você tentar uma divisão por 0.

1. Para depurar o programa, pressione **F5** ou escolha o botão da barra de ferramentas **Depurador Local do Windows** que tem um ícone de seta verde. Em seu aplicativo de console, se você digitar algo como "0-5", o programa se comportará normalmente e continuará em execução. No entanto, se você digitar "10 / 0", ele fará uma pausa no ponto de interrupção. Você pode até mesmo colocar qualquer número de espaços entre o operador e os números. `cin` é inteligente o suficiente para analisar a entrada de modo adequado.

   ![Vídeo curto do Visual estúdios mostrando que o programa está em pausa no ponto de interrupção condicional.](./media/calculator-debug-conditional.gif "Pausar no ponto de interrupção condicional")

### <a name="useful-windows-in-the-debugger"></a>Janelas úteis no depurador

Sempre que você depura seu código, pode perceber que algumas novas janelas aparecem. Essas janelas podem ajudar a sua experiência de depuração. Dê uma olhada na janela **Autos**. A janela **Autos** mostra os valores atuais das variáveis usadas pelo menos três linhas antes e até a linha atual.

   ![A janela automáticos](./media/calculator-autos.png "A janela automáticos")

Para ver todas as variáveis dessa função, alterne para a janela **Locais**. Na verdade, você pode modificar os valores dessas variáveis enquanto depura para ver que efeito elas teriam sobre o programa. Neste caso, podemos deixá-las de lado.

   ![Captura de tela da janela locais.](./media/calculator-locals.png "A janela locais")

Também é possível apenas focalizar variáveis no código em si para ver seus valores atuais em que a execução está em pausa momento. Verifique se a janela do editor está em foco clicando nela primeiro.

   ![Vídeo curto mostrando a dica de ferramenta que aparece exibindo o valor da variável.](./media/calculator-hover-tooltip.gif "Focalizar para exibir valores de variáveis atuais")

### <a name="to-continue-debugging"></a>Para continuar a depuração

1. A linha amarela à esquerda mostra o ponto atual de execução. A linha atual que chama `Calculate`, assim, pressione **F11** para **Depurar** a função. Você se encontrará no corpo da função `Calculate`. Atenção ao **Depurar**; se fizer isso muitas vezes, poderá perder muito tempo. Ela entra em qualquer código que você usa na linha em que você está, incluindo funções de biblioteca padrão.

1. Agora que o ponto de execução está no início da função `Calculate`, pressione **F10** para ir para a próxima linha na execução do programa. **F10** também é conhecido como **Depuração Parcial**. Você pode usar **Depuração Parcial** para mover de uma linha para outra, sem aprofundar-se nos detalhes do que está ocorrendo em cada parte da linha. Em geral, você deve usar **Depuração Parcial** em vez de **Depurar**, a menos que queira aprofundar-se no código que está sendo chamado de outro lugar (como você fez para alcançar o corpo de `Calculate`).

1. Continue usando **F10** para realizar a **Depuração Parcial** de cada linha até que você voltar para a função `main()` no outro arquivo e pare na linha `cout`.

   ![Sair do cálculo e verificar o resultado](./media/calculator-undefined-zero.gif "Sair do cálculo e verificar o resultado")

   Parece que o programa está fazendo o que é esperado: ele usa o primeiro número e o divide pelo segundo. Na linha `cout`, focalize a variável `result` ou dê uma olhada `result` na janela **Autos**. Você verá que seu valor está listado como "inf", o que não parece correto, então vamos corrigi-lo. A linha `cout` somente gera qualquer valor que esteja armazenado em `result`, portanto, quando você avança mais uma linha usando **F10**, a janela do console exibe:

   ![Captura de tela da Microsoft Visual Studio console de depuração mostrando o resultado da divisão por zero.](./media/calculator-divide-by-zero-fail.png "O resultado da divisão por zero")

   Esse resultado acontece porque a divisão por zero é indefinida, portanto, o programa não tem uma resposta numérica para a operação solicitada.

### <a name="to-fix-the-divide-by-zero-error"></a>Para consertar o erro de "dividir por zero"

Vamos tratar da divisão por zero de modo mais simples para que um usuário possa entender o problema.

1. Faça as seguintes alterações a *CalculatorTutorial.cpp*. (Você pode deixar o programa em execução durante a edição, graças a um recurso do depurador chamado **Editar e Continuar**):

    ```cpp
    // CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
    //

    #include "pch.h"
    #include <iostream>
    #include "Calculator.h"

    using namespace std;

    int main()
    {
        double x = 0.0;
        double y = 0.0;
        double result = 0.0;
        char oper = '+';

        cout << "Calculator Console Application" << endl << endl;
        cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b" << endl;

        Calculator c;
        while (true)
        {
            cin  >> x  >> oper  >> y;
            if (oper == '/' && y == 0)
            {
                cout << "Division by 0 exception" << endl;
                continue;
            }
            else
            {
                result = c.Calculate(x, oper, y);
            }
            cout << "Result is: " << result << endl;
        }

        return 0;
    }
    ```

1. Agora pressione **F5** uma vez. A execução do programa continua até ele precisar pausar para pedir entrada do usuário. Insira `10 / 0` novamente. Agora, é impressa uma mensagem mais útil. O usuário é solicitado a fornecer mais entradas e o programa continua em execução normalmente.

   ![Vídeo curto da Microsoft Visual Studio console de depuração mostrando o resultado final após as alterações.](./media/calculator-final-verification.gif "O resultado final após as alterações")

   > [!Note]
   > Quando você edita o código no modo de depuração, há um risco de o código se tornar obsoleto. Isso acontece quando o depurador ainda está executando seu código antigo e não ainda o atualizou com suas alterações. O depurador abre em pop-up uma caixa de diálogo para informá-lo quando isso acontece. Às vezes, pode ser necessário pressionar **F5** para atualizar o código que está sendo executado. Em particular, se você fizer uma alteração dentro de uma função enquanto o ponto de execução está dentro daquela função, precisará sair da função e voltar para ela para obter o código atualizado. Se isso não funcionar por alguma razão e você vir uma mensagem de erro, você poderá interromper a depuração clicando no quadrado vermelho na barra de ferramentas abaixo dos menus na parte superior do IDE e iniciar a depuração novamente inserindo **F5** ou escolhendo a seta " reproduzir" verde ao lado do botão Parar na barra de ferramentas.

   > Noções básicas sobre os atalhos de Executar e Depurar
   >
   > - **F5** (ou **Depurar** > **Iniciar Depuração**) iniciará uma sessão de depuração se uma ainda não estiver ativa e executará o programa até atingir um ponto de interrupção ou o programa precisar de entrada do usuário. Se nenhuma entrada do usuário for necessária e nenhum ponto de interrupção estiver disponível para ser atingido, o programa será encerrado e a janela do console fechará mesmo quando o programa for encerrado. Se você tiver algo parecido com um programa "Olá, Mundo" para ser executado, use **CTRL+F5** ou defina um ponto de interrupção antes de inserir **F5** para manter a janela aberta.
   > - **CTRL + F5** (ou **Depurar** > **Iniciar sem Depuração**) executa o aplicativo sem entrar no modo de depuração. Isso é um pouco mais rápido do que a depuração e a janela do console permaneça aberta depois de o programa terminar a execução.
   > - **F10** (conhecido como **Depuração Parcial**) permite que você itere pelo código linha por linha e visualize como o código é executado e quais valores de variáveis estão em cada etapa de execução.
   > - **F11** (conhecido como **Depurar**) funciona da mesma forma que **Depuração Parcial**, exceto que depura todas as funções chamadas na linha de execução. Por exemplo, se a linha que está sendo executada chamar uma função, pressionar **F11** moverá o ponteiro para o corpo da função, de modo que você possa seguir o código da função que está em execução antes de voltar para a linha em que começou. Pressionar **F10** faz a depuração parcial da chamada de função e apenas se move para a próxima linha; a chamada de função ainda acontece, mas o programa não pausa para mostrar o você está fazendo.

### <a name="close-the-app"></a>Feche o aplicativo

- Se ele ainda estiver em execução, feche a janela de console para o aplicativo de calculadora.

## <a name="the-finished-app"></a>O aplicativo finalizado

Parabéns! Você concluiu o código para o aplicativo de calculadora e o compilou e depurou no Visual Studio.

## <a name="next-steps"></a>Próximas etapas

[Saiba mais sobre o Visual Studio para C++](https://devblogs.microsoft.com/cppblog/getting-started-with-visual-studio-for-c-and-cpp-development/)

::: moniker-end
