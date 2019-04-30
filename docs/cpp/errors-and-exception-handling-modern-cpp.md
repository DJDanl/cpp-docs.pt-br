---
title: Erros e tratamento de exceções (C++ moderno)
ms.date: 09/17/2018
ms.topic: conceptual
ms.assetid: a6c111d0-24f9-4bbb-997d-3db4569761b7
ms.openlocfilehash: c3def77d8b7a22be05259784e3b80562c8728c15
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62398908"
---
# <a name="errors-and-exception-handling-modern-c"></a>Erros e tratamento de exceções (C++ moderno)

No C++ moderno, na maioria dos cenários, a maneira preferencial de relatar e manipular erros lógicos e erros de tempo de execução é usar exceções. Isso é especialmente verdadeiro quando a pilha talvez contenha várias chamadas de função entre a função que detecta o erro e a função que tem o contexto para saber como manipulá-lo. As exceções oferecem uma maneira formal e bem definida para o código que detecta erros para transmitir as informações da pilha de chamadas.

Erros de programa estão geralmente divididos em duas categorias: erros lógicos causados por erros de programação, por exemplo, um erro "Índice fora do intervalo" e erros de tempo de execução que estão além do controle do programador, por exemplo, um "serviço de rede indisponível" erro. Na programação de estilo C e em COM, relatório de erros é gerenciado retornando um valor que representa um código de erro ou um código de status para uma função específica, ou definindo uma variável global que o chamador pode opcionalmente recuperar após cada chamada de função para ver Se o erro foi relatado. Por exemplo, a programação COM usa o valor de retorno HRESULT para comunicar erros ao chamador e a API do Win32 tem a função GetLastError para recuperar o último erro foi relatado pela pilha de chamadas. Em ambos os casos, cabe ao chamador reconhecer o código e responder adequadamente a ele. Se o chamador não tratar explicitamente o código de erro, o programa pode falhar sem aviso ou continuar a executar com dados incorretos e produzir resultados incorretos.

As exceções são preferenciais no C++ moderno pelos seguintes motivos:

- Uma exceção força o código de chamada para reconhecer uma condição de erro e tratá-la. Exceções sem tratamento parar a execução do programa.

- Uma exceção pula para o ponto na pilha de chamadas que pode lidar com o erro. As funções intermediárias podem deixar a exceção propagar. Eles não precisam coordenar com outras camadas.

- O mecanismo de desenrolamento de pilha de exceção destrói todos os objetos no escopo de acordo com as regras bem definidas após uma exceção será lançada.

- Uma exceção permite uma separação clara entre o código que detecta o erro e o código que trata o erro.

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

Exceções em C++ são semelhantes àquelas em linguagens como c# e Java. No **tente** bloquear, se uma exceção é *lançada* será *capturada* pela primeira associado **catch** bloco cujo tipo corresponde do exceção. Em outras palavras, a execução vai dos **lançar** instrução para o **catch** instrução. Se nenhum bloco catch for encontrado, `std::terminate` é invocado e o programa será encerrado. No C++, qualquer tipo pode ser lançado; No entanto, recomendamos que você lança um tipo que deriva direta ou indiretamente `std::exception`. No exemplo anterior, o tipo de exceção [invalid_argument](../standard-library/invalid-argument-class.md), é definido na biblioteca padrão no [ \<stdexcept >](../standard-library/stdexcept.md) arquivo de cabeçalho. C++ não fornece e não requer uma **finalmente** bloco para certificar-se de que todos os recursos são liberados se uma exceção é lançada. A aquisição de recurso é o idioma de inicialização (RAII), que usa ponteiros inteligentes, oferece a funcionalidade necessária para limpeza de recursos. Para obter mais informações, confira [Como: Design para segurança de exceção](../cpp/how-to-design-for-exception-safety.md). Para obter informações sobre o mecanismo de desenrolamento de pilha do C++, consulte [exceções e desenrolamento de pilha](../cpp/exceptions-and-stack-unwinding-in-cpp.md).

## <a name="basic-guidelines"></a>Diretrizes básicas

Tratamento de erro robusta é desafiadora em qualquer linguagem de programação. Embora as exceções forneçam vários recursos que dão suporte à manipulação de erros adequada, eles não podem fazer todo o trabalho para você. Para obter os benefícios do mecanismo de exceção, tenha as exceções em mente ao projetar seu código.

- Use as verificações para verificar se há erros que nunca deveriam ocorrer. Use exceções para verificar se há erros que possam ocorrer, por exemplo, erros na validação de entrada em parâmetros de funções públicas. Para obter mais informações, consulte a seção intitulada **exceções vs. Asserções**.

- Use as exceções quando o código que trata o erro pode ser separado do código que detecta o erro por um ou mais chamadas de função interveniente. Considere a possibilidade de usar códigos de erro em vez disso, em loops de desempenho crítico quando o código que trata o erro estiver estritamente acoplado ao código que detecta.

- Para cada função que pode lançar ou propagar uma exceção, forneça um dos três garantias de exceção: a garantia de alta segurança, a garantia básica ou a garantia de nothrow (noexcept). Para obter mais informações, confira [Como: Design para segurança de exceção](../cpp/how-to-design-for-exception-safety.md).

- Lance exceções por valor, capture-as por referência. Você não captura o que você não pode manipular.

- Não use especificações de exceção, que foram preteridas no c++11. Para obter mais informações, consulte a seção intitulada **especificações de exceção e noexcept**.

- Use os tipos de exceção de biblioteca padrão quando elas se aplicam. Derivar tipos de exceção personalizada do [classe exception](../standard-library/exception-class.md) hierarquia.

- Não permitir exceções escapem dos destruidores ou funções de desalocação de memória.

## <a name="exceptions-and-performance"></a>Exceções e desempenho

O mecanismo de exceção tem um desempenho mínimo custo se nenhuma exceção é lançada. Se uma exceção for lançada, o custo da passagem de pilha e de desenrolamento são aproximadamente comparável ao custo de uma chamada de função. Estruturas de dados adicionais são necessários para rastrear a pilha de chamadas após um **tente** se entra no bloco e instruções adicionais são necessárias para desenrolar a pilha se uma exceção é lançada. No entanto, na maioria dos cenários, o custo de desempenho e o volume de memória não é significativo. O efeito adverso de exceções no desempenho provavelmente será significativo somente em sistemas de memória muito restrita ou em loops de desempenho críticos em que um erro é muito provável que ocorram regularmente e o código para manipulá-lo está acoplado ao código que relata. Em qualquer caso, é impossível saber o custo real de exceções sem criar perfil e medir. Até mesmo em casos raros quando o custo é significativo, você pode avaliá-lo contra o aumento da exatidão, facilidade de manutenção mais fácil e outras vantagens que são fornecidas por uma política de exceção bem projetado.

## <a name="exceptions-vs-assertions"></a>Exceções x afirmações

Exceções e afirmações são dois mecanismos diferentes para detectar erros de tempo de execução em um programa. Use as verificações para testar condições durante o desenvolvimento do que nunca deve ser verdadeiro se todo o seu código está correto. Não há nenhuma razão para manipular esse erro usando uma exceção porque o erro indica que algo no código precisa ser corrigido e não representa uma condição que o programa deverá se recuperar em tempo de execução. Uma assert para execução na instrução para que você possa inspecionar o estado do programa no depurador; uma exceção retoma a execução do primeiro manipulador catch adequado. Use exceções para verificar as condições de erro que podem ocorrer em tempo de execução, mesmo se seu código estiver correto, por exemplo, "arquivo não encontrado" ou "memória insuficiente." Talvez você queira recuperar essas condições, mesmo se a recuperação apenas gera uma mensagem para um log e encerra o programa. Sempre verifique argumentos para funções públicas usando exceções. Mesmo que sua função é livre de erros, você não pode ter controle total sobre os argumentos que um usuário pode passar para ele.

## <a name="c-exceptions-versus-windows-seh-exceptions"></a>Exceções de C++ versus exceções SEH do Windows

Programas de C e C++ podem usar a mecanismo (SEH) no sistema operacional Windows de tratamento de exceções estruturado. Os conceitos no SEH lembram os no C++ exceções, exceto que o SEH usa o **Try**, **EXCEPT**, e **Finally** constrói, em vez de **tente**  e **catch**. No Visual C++, exceções do C++ são implementadas para SEH. No entanto, quando você escreve código C++, use a sintaxe de exceção do C++.

Para obter mais informações sobre SEH, consulte [tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md).

## <a name="exception-specifications-and-noexcept"></a>Especificações de exceção e noexcept

Especificações de exceção foram introduzidas no C++ como uma maneira de especificar que uma função pode lançar exceções. No entanto, as especificações de exceção foram comprovadas como problemáticas na prática e foram preteridas no padrão C + + 11 rascunho. É recomendável que você não use especificações de exceção, exceto para `throw()`, que indica que a função permite que nenhuma exceção escape. Se você precisar usar as especificações de exceção do tipo `throw(` *tipo*`)`, lembre-se de que o Visual C++ foge do padrão de determinadas maneiras. Para obter mais informações, consulte [especificações de exceção (lançar)](../cpp/exception-specifications-throw-cpp.md). O `noexcept` especificador é introduzido no c++11 como a alternativa preferida para `throw()`.

## <a name="see-also"></a>Consulte também

[Como: realizar a interface entre códigos excepcionais e não excepcionais](../cpp/how-to-interface-between-exceptional-and-non-exceptional-code.md)<br/>
[Bem-vindo ao C++ (C++ moderno)](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
