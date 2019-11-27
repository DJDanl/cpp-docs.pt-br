---
title: Práticas C++ recomendadas modernas para exceções e tratamento de erros
ms.date: 11/19/2019
ms.topic: conceptual
ms.assetid: a6c111d0-24f9-4bbb-997d-3db4569761b7
ms.openlocfilehash: 85a8bf0f64681387cbee63f273fda5ce93ab7ad5
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74245860"
---
# <a name="modern-c-best-practices-for-exceptions-and-error-handling"></a>Práticas C++ recomendadas modernas para exceções e tratamento de erros

No moderno C++, na maioria dos cenários, a maneira preferida de relatar e lidar com erros lógicos e erros de tempo de execução é usar exceções. Isso é especialmente verdadeiro quando a pilha pode conter várias chamadas de função entre a função que detecta o erro e a função que tem o contexto para saber como tratá-lo. As exceções fornecem uma maneira formal e bem definida para o código que detecta erros para passar as informações para a pilha de chamadas.

Erros de programa geralmente são divididos em duas categorias: erros lógicos causados por erros de programação, por exemplo, um erro de "índice fora do intervalo" e erros de tempo de execução que estão além do controle do programador, por exemplo, um "serviço de rede não disponível" ao. Na programação em estilo C e no COM, o relatório de erros é gerenciado retornando um valor que representa um código de erro ou um código de status para uma função específica ou definindo uma variável global que o chamador pode opcionalmente recuperar depois de cada chamada de função para ver se foram relatados erros. Por exemplo, a programação COM usa o valor de retorno HRESULT para comunicar erros ao chamador, e a API do Win32 tem a função GetLastError para recuperar o último erro relatado pela pilha de chamadas. Em ambos os casos, cabe ao chamador reconhecer o código e respondê-lo adequadamente. Se o chamador não tratar explicitamente o código de erro, o programa poderá falhar sem aviso ou continuar a ser executado com dados incorretos e produzir resultados incorretos.

As exceções são preferenciais C++ em Modern pelos seguintes motivos:

- Uma exceção força o código de chamada a reconhecer uma condição de erro e tratá-la. As exceções não tratadas param a execução do programa.

- Uma exceção salta para o ponto na pilha de chamadas que pode manipular o erro. As funções intermediárias podem permitir que a exceção seja propagada. Eles não precisam coordenar com outras camadas.

- O mecanismo de desenrolamento de pilha de exceção destrói todos os objetos no escopo de acordo com as regras bem definidas após a geração de uma exceção.

- Uma exceção permite uma separação clara entre o código que detecta o erro e o código que manipula o erro.

O exemplo simplificado a seguir mostra a sintaxe necessária para lançar e capturar C++exceções no.

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

As exceções C++ são semelhantes às de linguagens como C# e Java. No bloco **try** , se uma exceção for *gerada* , ela será *detectada* pelo primeiro bloco **Catch** associado cujo tipo corresponde ao da exceção. Em outras palavras, a execução salta da instrução **throw** para a instrução **Catch** . Se nenhum bloco catch utilizável for encontrado, `std::terminate` será invocado e o programa sairá. No C++, qualquer tipo pode ser lançado; no entanto, é recomendável que você gere um tipo que derive direta ou indiretamente de `std::exception`. No exemplo anterior, o tipo de exceção, [invalid_argument](../standard-library/invalid-argument-class.md), é definido na biblioteca padrão no arquivo de cabeçalho [\<stdexcept >](../standard-library/stdexcept.md) . C++não fornece, e não requer, um bloco **finally** para garantir que todos os recursos sejam liberados se uma exceção for lançada. O idioma de RAII (aquisição de recursos é inicialização), que usa ponteiros inteligentes, fornece a funcionalidade necessária para a limpeza de recursos. Para obter mais informações, consulte [como: design para segurança de exceção](how-to-design-for-exception-safety.md). Para obter informações sobre C++ o mecanismo de desenrolamento de pilha, consulte [exceções e desenrolamento de pilha](exceptions-and-stack-unwinding-in-cpp.md).

## <a name="basic-guidelines"></a>Diretrizes básicas

O tratamento de erros robusto é desafiador em qualquer linguagem de programação. Embora as exceções forneçam vários recursos que dão suporte a um bom tratamento de erros, elas não podem fazer todo o trabalho para você. Para obter os benefícios do mecanismo de exceção, mantenha as exceções em mente ao projetar seu código.

- Use declarações para verificar se há erros que nunca devem ocorrer. Use exceções para verificar se há erros que podem ocorrer, por exemplo, erros na validação de entrada em parâmetros de funções públicas. Para obter mais informações, consulte a seção intitulada **exceções vs. asserções**.

- Use exceções quando o código que manipula o erro pode ser separado do código que detecta o erro por uma ou mais chamadas de função intermediárias. Considere se os códigos de erro devem ser usados em loops críticos de desempenho quando o código que manipula o erro está rigidamente acoplado ao código que o detecta.

- Para cada função que pode lançar ou propagar uma exceção, forneça uma das três garantias de exceção: a garantia forte, a garantia básica ou a garantia nothrow (noexcept). Para obter mais informações, consulte [como: design para segurança de exceção](how-to-design-for-exception-safety.md).

- Lançar exceções por valor, capturá-las por referência. Não pegue o que não é possível manipular.

- Não use especificações de exceção, que são preteridas no C++ 11. Para obter mais informações, consulte a seção intitulada **especificações de exceção e noexcept**.

- Use tipos de exceção de biblioteca padrão quando eles se aplicarem. Derive tipos de exceção personalizados da hierarquia de [classe de exceção](../standard-library/exception-class.md) .

- Não permita que exceções escapem de destruidores ou de funções de desalocação de memória.

## <a name="exceptions-and-performance"></a>Exceções e desempenho

O mecanismo de exceção tem um custo de desempenho muito mínimo se nenhuma exceção for gerada. Se uma exceção for lançada, o custo da passagem de pilha e o desenrolamento serão aproximadamente comparáveis ao custo de uma chamada de função. Estruturas de dados adicionais são necessárias para acompanhar a pilha de chamadas depois que um bloco **try** é inserido e instruções adicionais são necessárias para desenrolar a pilha se uma exceção for lançada. No entanto, na maioria dos cenários, o custo no desempenho e no volume de memória não é significativo. O efeito adverso de exceções no desempenho provavelmente será significativo apenas em sistemas com restrição de memória ou em loops de desempenho crítico, em que um erro provavelmente ocorrerá regularmente e o código para tratá-lo está rigidamente acoplado ao código que o relata. Em qualquer caso, é impossível saber o custo real das exceções sem a criação de perfil e a medição. Mesmo nesses casos raros, quando o custo é significativo, você pode pesar isso com a maior exatidão, facilidade de manutenção e outras vantagens que são fornecidas por uma política de exceção bem projetada.

## <a name="exceptions-vs-assertions"></a>Exceções vs. asserções

Exceções e declarações são dois mecanismos distintos para detectar erros em tempo de execução em um programa. Use declarações para testar condições durante o desenvolvimento que nunca devem ser verdadeiras se todo o código estiver correto. Não há nenhum ponto na manipulação desse tipo de erro usando uma exceção porque o erro indica que algo no código deve ser corrigido e não representa uma condição que o programa precisa recuperar em tempo de execução. Uma declaração interrompe a execução na instrução para que você possa inspecionar o estado do programa no depurador; uma exceção continua a execução do primeiro manipulador catch apropriado. Use exceções para verificar condições de erro que podem ocorrer em tempo de execução, mesmo que seu código esteja correto, por exemplo, "arquivo não encontrado" ou "memória insuficiente". Talvez você queira se recuperar dessas condições, mesmo que a recuperação apenas gere uma mensagem para um log e encerre o programa. Sempre verifique os argumentos para funções públicas usando exceções. Mesmo que sua função seja sem erros, talvez você não tenha controle total sobre os argumentos que um usuário pode passar para ele.

## <a name="c-exceptions-versus-windows-seh-exceptions"></a>C++exceções versus exceções de SEH do Windows

Tanto C quanto C++ programas podem usar o mecanismo de manipulação de exceção estruturada (SEH) no sistema operacional Windows. Os conceitos em SEH são semelhantes àqueles C++ em exceções, exceto que o SEH usa as construções **__try**, **__except**e **__finally** em vez de **try** e **Catch**. No compilador Microsoft C++ (MSVC), C++ as exceções são implementadas para SEH. No entanto, quando C++ você escreve o código C++ , use a sintaxe de exceção.

Para obter mais informações sobre SEH, consulte [manipulação de exceção estruturadaC++(C/)](structured-exception-handling-c-cpp.md).

## <a name="exception-specifications-and-noexcept"></a>Especificações de exceção e noexcept

As especificações de exceção foram C++ introduzidas no como uma maneira de especificar as exceções que uma função pode gerar. No entanto, as especificações de exceção provaram problemas na prática e foram preteridas no padrão de rascunho do C++ 11. Recomendamos que você não use especificações de exceção, exceto `throw()`, que indica que a função não permite escape de exceções. Se você precisar usar especificações de exceção do tipo `throw(`*tipo*`)`, lembre-se de que o MSVC faz parte do padrão de determinadas maneiras. Para obter mais informações, consulte [especificações de exceção (throw)](exception-specifications-throw-cpp.md). O especificador de `noexcept` é introduzido no C++ 11 como a alternativa preferida ao `throw()`.

## <a name="see-also"></a>Consulte também

[Como realizar a interface entre códigos excepcionais e não excepcionais](../cpp/how-to-interface-between-exceptional-and-non-exceptional-code.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
