---
title: Práticas recomendadas do C++ moderno para exceções e tratamento de erros
description: Como o C++ moderno dá suporte a estilos de programação excepcionais em códigos de erro.
ms.date: 08/24/2020
ms.topic: conceptual
ms.assetid: a6c111d0-24f9-4bbb-997d-3db4569761b7
ms.openlocfilehash: b402c93ea5af3cc7dab418b6dea58446ae300c67
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898373"
---
# <a name="modern-c-best-practices-for-exceptions-and-error-handling"></a>Práticas recomendadas do C++ moderno para exceções e tratamento de erros

No C++ moderno, na maioria dos cenários, a maneira preferida de relatar e lidar com erros lógicos e erros de tempo de execução é usar exceções. Ele é especialmente verdadeiro quando a pilha pode conter várias chamadas de função entre a função que detecta o erro e a função que tem o contexto para manipular o erro. As exceções fornecem uma maneira formal e bem definida para o código que detecta erros para passar as informações para a pilha de chamadas.

## <a name="use-exceptions-for-exceptional-code"></a>Usar exceções para código excepcional

Erros de programa geralmente são divididos em duas categorias: erros lógicos causados por erros de programação, por exemplo, um erro de "índice fora do intervalo". E os erros de tempo de execução que estão além do controle do programador, por exemplo, um erro "serviço de rede indisponível". Na programação em estilo C e no COM, o relatório de erros é gerenciado retornando um valor que representa um código de erro ou um código de status para uma função específica, ou definindo uma variável global que o chamador pode opcionalmente recuperar depois de cada chamada de função para ver se erros foram relatados. Por exemplo, a programação COM usa o valor de retorno HRESULT para comunicar erros ao chamador. E a API do Win32 tem a `GetLastError` função para recuperar o último erro relatado pela pilha de chamadas. Em ambos os casos, cabe ao chamador reconhecer o código e respondê-lo adequadamente. Se o chamador não tratar explicitamente o código de erro, o programa poderá falhar sem aviso. Ou, ele pode continuar a ser executado usando dados incorretos e produzir resultados incorretos.

As exceções são preferenciais no C++ moderno pelos seguintes motivos:

- Uma exceção força o código de chamada a reconhecer uma condição de erro e tratá-la. As exceções não tratadas param a execução do programa.

- Uma exceção salta para o ponto na pilha de chamadas que pode manipular o erro. As funções intermediárias podem permitir que a exceção seja propagada. Eles não precisam coordenar com outras camadas.

- O mecanismo de desenrolamento de pilha de exceção destrói todos os objetos no escopo após a geração de uma exceção, de acordo com as regras bem definidas.

- Uma exceção permite uma separação clara entre o código que detecta o erro e o código que manipula o erro.

O exemplo simplificado a seguir mostra a sintaxe necessária para lançar e capturar exceções em C++.

```cpp
#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

void MyFunc(int c)
{
    if (c > numeric_limits< char> ::max())
        throw invalid_argument("MyFunc argument too large.");
    //...
}

int main()
{
    try
    {
        MyFunc(256); //cause an exception to throw
    }

    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    //...
    return 0;
}
```

As exceções em C++ parecem aquelas em linguagens como C# e Java. No **`try`** bloco, se uma exceção for *gerada* , ela será *detectada* pelo primeiro bloco associado **`catch`** cujo tipo corresponde ao da exceção. Em outras palavras, a execução salta da **`throw`** instrução para a **`catch`** instrução. Se nenhum bloco catch utilizável for encontrado, `std::terminate` é invocado e o programa é encerrado. Em C++, qualquer tipo pode ser lançado; no entanto, é recomendável que você gere um tipo que derive direta ou indiretamente do `std::exception` . No exemplo anterior, o tipo de exceção, [`invalid_argument`](../standard-library/invalid-argument-class.md) , é definido na biblioteca padrão no arquivo de [`<stdexcept>`](../standard-library/stdexcept.md) cabeçalho. O C++ não fornece ou exige um **`finally`** bloco para garantir que todos os recursos sejam liberados se uma exceção for lançada. O idioma de RAII (aquisição de recursos é inicialização), que usa ponteiros inteligentes, fornece a funcionalidade necessária para a limpeza de recursos. Para obter mais informações, consulte [como: design para segurança de exceção](how-to-design-for-exception-safety.md). Para obter informações sobre o mecanismo de desenrolamento de pilha C++, consulte [exceções e desenrolamento de pilha](exceptions-and-stack-unwinding-in-cpp.md).

## <a name="basic-guidelines"></a>Diretrizes básicas

O tratamento de erros robusto é desafiador em qualquer linguagem de programação. Embora as exceções forneçam vários recursos que dão suporte a um bom tratamento de erros, elas não podem fazer todo o trabalho para você. Para obter os benefícios do mecanismo de exceção, mantenha as exceções em mente ao projetar seu código.

- Use declarações para verificar se há erros que nunca devem ocorrer. Use exceções para verificar se há erros que podem ocorrer, por exemplo, erros na validação de entrada em parâmetros de funções públicas. Para obter mais informações, consulte a seção [exceções versus asserções](#exceptions_versus_assertions) .

- Use exceções quando o código que manipula o erro é separado do código que detecta o erro por uma ou mais chamadas de função intermediárias. Considere se os códigos de erro devem ser usados em loops críticos de desempenho, quando o código que manipula o erro está rigidamente acoplado ao código que o detecta.

- Para cada função que pode lançar ou propagar uma exceção, forneça uma das três garantias de exceção: a garantia forte, a garantia básica ou a garantia nothrow (noexcept). Para obter mais informações, consulte [como: design para segurança de exceção](how-to-design-for-exception-safety.md).

- Lançar exceções por valor, capturá-las por referência. Não pegue o que não é possível manipular.

- Não use especificações de exceção, que são preteridas no C++ 11. Para obter mais informações, consulte as [especificações e `noexcept` ](#exception_specifications_and_noexcept) a seção de exceção.

- Use tipos de exceção de biblioteca padrão quando eles se aplicarem. Derive tipos de exceção personalizados da hierarquia de [ `exception` classes](../standard-library/exception-class.md) .

- Não permita que exceções escapem de destruidores ou de funções de desalocação de memória.

## <a name="exceptions-and-performance"></a>Exceções e desempenho

O mecanismo de exceção tem um custo de desempenho mínimo se nenhuma exceção for gerada. Se uma exceção for lançada, o custo da passagem de pilha e o desenrolamento serão aproximadamente comparáveis ao custo de uma chamada de função. Estruturas de dados adicionais são necessárias para rastrear a pilha de chamadas depois que um **`try`** bloco é inserido e instruções adicionais são necessárias para desenrolar a pilha se uma exceção for lançada. No entanto, na maioria dos cenários, o custo no desempenho e no volume de memória não é significativo. O efeito adverso de exceções no desempenho provavelmente será significativo apenas em sistemas com restrição de memória. Ou, em loops de desempenho crítico, em que é provável que um erro ocorra regularmente e haja acoplamento forte entre o código para tratá-lo e o código que o relata. Em qualquer caso, é impossível saber o custo real das exceções sem a criação de perfil e a medição. Mesmo nesses casos raros, quando o custo é significativo, você pode pesar isso com a maior exatidão, facilidade de manutenção e outras vantagens que são fornecidas por uma política de exceção bem projetada.

## <a name="exceptions-versus-assertions"></a><a name="exceptions_versus_assertions"></a> Exceções versus asserções

Exceções e declarações são dois mecanismos distintos para detectar erros em tempo de execução em um programa. Use `assert` instruções para testar condições durante o desenvolvimento que nunca devem ser verdadeiras se todo o código estiver correto. Não há nenhum ponto em lidar com esse erro usando uma exceção, porque o erro indica que algo no código deve ser corrigido. Ele não representa uma condição que o programa precisa recuperar em tempo de execução. Um `assert` interrompe a execução na instrução para que você possa inspecionar o estado do programa no depurador. Uma exceção continua a execução do primeiro manipulador catch apropriado. Use exceções para verificar condições de erro que podem ocorrer em tempo de execução, mesmo que seu código esteja correto, por exemplo, "arquivo não encontrado" ou "memória insuficiente". As exceções podem lidar com essas condições, mesmo que a recuperação apenas gere uma mensagem para um log e encerre o programa. Sempre verifique os argumentos para funções públicas usando exceções. Mesmo que sua função seja sem erros, talvez você não tenha controle total sobre os argumentos que um usuário pode passar para ele.

## <a name="c-exceptions-versus-windows-seh-exceptions"></a>Exceções de C++ versus exceções de SEH do Windows

Os programas C e C++ podem usar o mecanismo de manipulação de exceção estruturada (SEH) no sistema operacional Windows. Os conceitos em SEH se assemelham àqueles em exceções C++, exceto que o SEH usa as **`__try`** **`__except`** construções, e **`__finally`** em vez de **`try`** e **`catch`** . No compilador do Microsoft C++ (MSVC), as exceções do C++ são implementadas para SEH. No entanto, ao escrever código C++, use a sintaxe de exceção C++.

Para obter mais informações sobre SEH, consulte [manipulação de exceção estruturada (C/C++)](structured-exception-handling-c-cpp.md).

## <a name="exception-specifications-and-noexcept"></a><a name="exception_specifications_and_noexcept"></a> Especificações de exceção e `noexcept`

As especificações de exceção foram introduzidas em C++ como uma maneira de especificar as exceções que uma função pode gerar. No entanto, as especificações de exceção provaram problemas na prática e foram preteridas no padrão de rascunho do C++ 11. Recomendamos que você não use as **`throw`** especificações de exceção `throw()` , exceto para, o que indica que a função não permite a saída de nenhuma exceção. Se você precisar usar especificações de exceção da forma preterida `throw( type-name )` , o suporte a MSVC será limitado. Para obter mais informações, consulte [especificações de exceção (throw)](exception-specifications-throw-cpp.md). O **`noexcept`** especificador é introduzido no c++ 11 como a alternativa preferida ao `throw()` .

## <a name="see-also"></a>Confira também

[Como: interface entre códigos excepcionais e não excepcionais](../cpp/how-to-interface-between-exceptional-and-non-exceptional-code.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
