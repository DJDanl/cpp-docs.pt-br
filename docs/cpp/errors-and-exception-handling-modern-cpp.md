---
title: "Erros e tratamento de exceções (C++ moderno) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: a6c111d0-24f9-4bbb-997d-3db4569761b7
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5b1ee1c7307f4e19db4ca0b7d03e218b0916538c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="errors-and-exception-handling-modern-c"></a>Erros e tratamento de exceções (C++ moderno)
No C++ moderna, na maioria dos cenários, a melhor maneira de relatório e tratar erros de lógica e erros de tempo de execução é usar exceções. Isso é especialmente verdadeiro quando a pilha pode conter várias chamadas de função entre a função que detecta o erro e a função que tem o contexto para saber como lidar com ele. Exceções fornecem uma maneira formal e bem definida para o código que detecta erros para passar as informações de pilha de chamadas.  
  
 Erros de programa geralmente são divididos em duas categorias: erros de lógica que são causados por programação erros, por exemplo, um erro "Índice fora do intervalo" e erros de tempo de execução que estão fora do controle do programador, por exemplo, um "serviço de rede não está disponível" erro. Na programação do estilo C e COM, o relatório de erros é gerenciado, retornando um valor que representa um código de status para uma função específica ou um código de erro ou definindo uma variável global que o chamador pode, opcionalmente, recuperar após cada chamada de função para ver Se o erro foi relatado. Por exemplo, programação COM usa o valor de retorno HRESULT para comunicar erros ao chamador, e a API do Win32 tem a função GetLastError para recuperar o último erro foi relatado pela pilha de chamada. Em ambos os casos, ele é para o chamador para o código de reconhecer e responder adequadamente a ele. Se o chamador não explicitamente lidar com o código de erro, o programa pode falhar sem aviso ou continuar a executar com dados incorretos e produzir resultados incorretos.  
  
 Exceções são preferenciais em C++ moderno pelos seguintes motivos:  
  
-   Uma exceção força o código de chamada para reconhecer uma condição de erro e tratá-la. Exceções não tratadas pararam a execução do programa.  
  
-   Uma exceção salta para o ponto na pilha de chamadas que pode lidar com o erro. Funções intermediárias podem permitir que a exceção se propagar. Eles não precisam coordenação com outras camadas.  
  
-   O mecanismo de desenrolamento de pilha de exceção destrói todos os objetos no escopo de acordo com as regras bem definidas depois que uma exceção será lançada.  
  
-   Uma exceção permite uma separação clara entre o código que detecta o erro e o código que manipula o erro.  
  
 O exemplo simplificado a seguir mostra a sintaxe necessária para gerar e capturar exceções em C++.  
  
```cpp  
#include <stdexcept>  
#include <limits>  
#include <iostream>  
  
using namespace std;  
class MyClass  
{  
public:  
   void MyFunc(char c)  
   {  
      if(c < numeric_limits<char>::max())  
         throw invalid_argument("MyFunc argument too large.");  
      //...  
   }  
};  
  
int main()  
{  
   try  
   {  
      MyFunc(256); //cause an exception to throw  
   }  
  
   catch(invalid_argument& e)  
   {  
      cerr << e.what() << endl;  
      return -1;  
   }  
   //...  
   return 0;  
}  
  
```  
  
 Exceções em C++ são semelhantes às em linguagens como c# e Java. No `try` bloquear, se uma exceção é *gerada* será *detectada* pelo primeiro associados `catch` bloco cujo tipo corresponda da exceção. Em outras palavras, a execução saltará do `throw` instrução para o `catch` instrução. Se nenhum bloco catch utilizável for encontrado, `std::terminate` é chamado e o programa será encerrado. No C++, qualquer tipo pode ser acionado; No entanto, é recomendável que você exiba um tipo que deriva diretamente ou indiretamente de `std::exception`. No exemplo anterior, o tipo de exceção, [invalid_argument](../standard-library/invalid-argument-class.md), é definido na biblioteca padrão no [ \<stdexcept >](../standard-library/stdexcept.md) arquivo de cabeçalho. C++ não fornece e não requer um `finally` bloco para certificar-se de que todos os recursos são liberados se uma exceção for lançada. A aquisição de recursos é o idioma de inicialização (RAII), que usa ponteiros inteligentes, fornece a funcionalidade necessária para limpeza de recursos. Para obter mais informações, consulte [como: Design para segurança de exceção](../cpp/how-to-design-for-exception-safety.md). Para obter informações sobre o mecanismo de desenrolamento de pilha do C++, consulte [exceções e desenrolamento de pilha](../cpp/exceptions-and-stack-unwinding-in-cpp.md).  
  
## <a name="basic-guidelines"></a>Diretrizes básicas  
 Tratamento de erro robustos é um desafio em qualquer linguagem de programação. Embora exceções fornecem vários recursos que dão suporte a BOM de tratamento de erros, eles não podem fazer todo o trabalho para você. Para obter os benefícios do mecanismo de exceção, tenha exceções em mente ao projetar seu código.  
  
-   Use declarações para verificar se há erros que nunca devem ocorrer. Use exceções para verificar se há erros que podem ocorrer, por exemplo, erros de validação de entrada nos parâmetros de funções públicas. Para obter mais informações, consulte a seção intitulada **exceções vs. Asserções**.  
  
-   Use exceções quando o código que manipula o erro pode ser separado do código que detecta o erro por um ou mais chamadas de função intermediários. Considere a possibilidade de usar códigos de erro em vez disso, em loops desempenho crítico quando o código que manipula o erro está estreitamente acoplado ao código que detecta. 
  
-   Para cada função que pode lançar ou propagar uma exceção, forneça as garantias de três exceções: a garantia de alta segurança, a garantia básica ou a garantia de nothrow (noexcept). Para obter mais informações, consulte [como: Design para segurança de exceção](../cpp/how-to-design-for-exception-safety.md).  
  
-   Gerar exceções por valor, percebê-los por referência. Não captura o que você não pode manipular. 
  
-   Não use especificações de exceção, que estão obsoletas no C++ 11. Para obter mais informações, consulte a seção intitulada **especificações de exceção e noexcept**.  
  
-   Use os tipos de exceção de biblioteca padrão quando elas se aplicam. A derivação de tipos de exceção personalizados do [classe exception](../standard-library/exception-class.md) hierarquia.  
  
-   Não permita exceções sair do destruidores ou funções de desalocação de memória.  
  
## <a name="exceptions-and-performance"></a>Desempenho e exceções  
 O mecanismo de exceção tem um desempenho muito pouca custo se nenhuma exceção for lançada. Se uma exceção for lançada, o custo de passagem de pilha e desenrolamento é aproximadamente comparável ao custo de uma chamada de função. Estruturas de dados adicionais são necessárias para rastrear a pilha de chamadas após um `try` bloco é inserido e instruções adicionais são necessárias para desenrolar a pilha se uma exceção for lançada. No entanto, na maioria dos cenários, o custo de desempenho e o espaço de memória não é significativo. A desvantagem de exceções no desempenho provavelmente significativa apenas em sistemas de memória muito restrita, ou no desempenho crítico loops em que um erro é provável que ocorram regularmente e o código para lidar com ele está acoplado ao código que informa. Em qualquer caso, é impossível saber o custo real de exceções sem a criação de perfil e medição. Mesmo em casos raros quando o custo é significativo, você pode avaliá-lo em relação à precisão maior facilidade de manutenção mais fácil e outras vantagens que são fornecidas por uma política de exceção bem projetado.  
  
## <a name="exceptions-vs-assertions"></a>Exceções versus asserções  
 Exceções e declarações são dois mecanismos distintos para detectar erros de tempo de execução em um programa. Use declarações para testar as condições de durante o desenvolvimento nunca deve ser true se todo o seu código está correto. Não há nenhum ponto de lidar com um erro usando uma exceção porque o erro indica que algo no código precisa ser corrigido e não representam uma condição em que o programa tenha para se recuperar de tempo de execução. Uma declaração para a execução na instrução para que você pode inspecionar o estado do programa no depurador; uma exceção continua a execução do primeiro manipulador catch apropriada. Use exceções para verificar se as condições de erro podem ocorrer em tempo de execução, mesmo se o código está correto, por exemplo, "arquivo não encontrado" ou "memória insuficiente." Você talvez queira recuperar essas condições, mesmo se a recuperação apenas gera uma mensagem em um log e encerra o programa. Sempre verifique os argumentos para funções públicas usando exceções. Mesmo se sua função é livre de erro, você não pode ter controle total sobre os argumentos que um usuário pode passar para ele.  
  
## <a name="c-exceptions-versus-windows-seh-exceptions"></a>Exceções de C++ em comparação com exceções SEH do Windows  
 Programas C e C++ podem usar o mecanismo (SEH) no sistema operacional Windows de tratamento estruturado de exceções. Os conceitos em SEH lembram as exceções do C++, exceto que usa SEH o `__try`, `__except`, e `__finally` construções em vez de `try` e `catch`. No Visual C++, exceções C++ são implementadas para SEH. No entanto, quando você escreve código C++, use a sintaxe de exceção de C++.  
  
 Para obter mais informações sobre SEH, consulte [manipulação de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md).  
  
## <a name="exception-specifications-and-noexcept"></a>Noexcept e especificações de exceção  
 Especificações de exceção foram introduzidas em C++, como uma maneira de especificar as exceções que pode gerar uma função. No entanto, especificações de exceção provado que ele é um problema na prática e foram preteridas no padrão C++ 11 rascunho. É recomendável que você não use especificações de exceção, exceto para `throw()`, que indica que a função permite sem exceções sair. Se você deve usar as especificações de exceção do tipo `throw(` *tipo*`)`, lembre-se de que o Visual C++ entregas do padrão de determinadas maneiras. Para obter mais informações, consulte [especificações de exceção (lançar)](../cpp/exception-specifications-throw-cpp.md). O `noexcept` especificador é introduzido no C++ 11 como a opção preferencial ao `throw()`.  
  
## <a name="see-also"></a>Consulte também  
 [Como: Interface entre códigos excepcional e não excepcional](../cpp/how-to-interface-between-exceptional-and-non-exceptional-code.md)   
 [Bem-vindo novamente para C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
