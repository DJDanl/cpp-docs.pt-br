---
title: "Erros e tratamento de exce&#231;&#245;es (C++ moderno) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: a6c111d0-24f9-4bbb-997d-3db4569761b7
caps.latest.revision: 19
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Erros e tratamento de exce&#231;&#245;es (C++ moderno)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em C++ moderno, na maioria das situações, a maneira preferencial para relatar e tratar erros lógicos e erros de tempo de execução é usar exceções. Isso é especialmente verdadeiro quando a pilha pode conter várias chamadas de função entre a função que detecta o erro e a função que tem o contexto para saber como lidar com ele. Exceções fornecem um modo formal e bem definido para o código que detecta erros para passar as informações de pilha de chamadas.  
  
 Erros de programa geralmente são divididos em duas categorias: erros lógicos que são causados por programação erros, por exemplo, um erro "Índice fora do intervalo" e erros de tempo de execução que estão além do controle do programador, por exemplo, um erro "serviço indisponível de rede". Relatório de erros é gerenciado na programação de estilo C e COM, retornando um valor que representa um código de erro ou um código de status para uma função específica ou definindo uma variável global que o chamador pode, opcionalmente, recuperar após cada chamada de função para ver se o erro foi relatado. Por exemplo, programação COM usa o valor de retorno HRESULT para comunicar erros ao chamador, e a API do Win32 tem a função GetLastError para recuperar o último erro foi relatado pela pilha de chamadas. Em ambos os casos, cabe ao chamador para reconhecer o código e respondê-la adequadamente. Se o chamador não lidar explicitamente com o código de erro, o programa pode falhar sem aviso ou continuar a executar com dados incorretos e produzir resultados incorretos.  
  
 Exceções são preferenciais em C++ moderno pelos seguintes motivos:  
  
-   Uma exceção força o código de chamada para reconhecer uma condição de erro e manipulá-lo. Exceções não tratadas Parar a execução do programa.  
  
-   Uma exceção salta para o ponto na pilha de chamadas que pode manipular o erro. Funções intermediárias podem permitir que a exceção se propagar. Eles não precisam coordenar com outras camadas.  
  
-   O mecanismo de desenrolamento de pilha de exceção destrói todos os objetos no escopo de acordo com regras bem definidas depois que uma exceção é lançada.  
  
-   Uma exceção permite uma separação clara entre o código que detecta o erro e o código que manipula o erro.  
  
 O exemplo simplificado a seguir mostra a sintaxe necessária para lançamento e captura exceções em C++.  
  
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
  
 Exceções em C++ semelhantes aos em linguagens como c# e Java. No `try` Bloquear, se uma exceção é *lançada* será *detectada* pelo primeiro associados `catch` bloco cujo tipo corresponda da exceção. Em outras palavras, a execução saltará do `throw` instrução para o `catch` instrução. Não se for localizado nenhum bloco catch utilizável, `std::terminate` é invocado e o programa será encerrado. No C++, qualquer tipo pode ser lançado; No entanto, recomendamos que você lança um tipo que deriva diretamente ou indiretamente de `std::exception`. No exemplo anterior, o tipo de exceção, [invalid_argument](../standard-library/invalid-argument-class.md), é definido na biblioteca padrão no [\< stdexcept>](../standard-library/stdexcept.md) arquivo de cabeçalho. C++ não oferece e não requer um `finally` bloco para certificar-se de que todos os recursos são liberados quando uma exceção é lançada. A aquisição de recurso é a linguagem de inicialização (RAII), que usa ponteiros inteligentes, fornece a funcionalidade necessária para limpeza de recursos. Para obter mais informações, consulte [como: Design de segurança de exceção](../cpp/how-to-design-for-exception-safety.md). Para obter informações sobre o mecanismo de desenrolamento de pilha do C++, consulte [exceções e desenrolamento de pilha](../cpp/exceptions-and-stack-unwinding-in-cpp.md).  
  
## <a name="basic-guidelines"></a>Diretrizes básicas  
 Tratamento de erros robusto é um desafio em qualquer linguagem de programação. Embora exceções fornecem vários recursos que dão suporte a BOM de tratamento de erros, eles não podem fazer todo o trabalho para você. Para obter os benefícios do mecanismo de exceção, tenha exceções em mente ao projetar seu código.  
  
-   Use asserções para verificar se há erros que nunca devem ocorrer. Use exceções para verificar erros que possam ocorrer, por exemplo, erros de validação de entrada nos parâmetros de funções públicas. Para obter mais informações, consulte a seção intitulada **exceções vs. Asserções**.  
  
-   Use exceções quando o código que manipula o erro pode ser separado do código que detecta o erro por um ou mais intermediários chamadas de função. Considere a possibilidade de usar códigos de erro em vez disso, em loops de desempenho crítico quando o código que manipula o erro é rigidamente acoplado ao código que detecta. Para obter mais informações sobre quando não usar exceções, consulte [(NOTINBUILD) quando não usar exceções](http://msdn.microsoft.com/pt-br/e810df8b-2217-4e81-bae5-02f0a69f1346).  
  
-   Para cada função que pode lançar ou propagar uma exceção, forneça as garantias de três exceções: a garantia de alta segurança, a garantia básica ou a garantia de nothrow (noexcept). Para obter mais informações, consulte [como: Design de segurança de exceção](../cpp/how-to-design-for-exception-safety.md).  
  
-   Lançar exceções por valor, capturá-las por referência. Não captura não pode manipular. Para obter mais informações, consulte [(NOTINBUILD) diretrizes para lançamento e captura de exceções (C++)](http://msdn.microsoft.com/pt-br/0a9b0a3a-64c5-43f5-a080-fca69b89e839).  
  
-   Não use as especificações de exceção, que estão obsoletas no C++ 11. Para obter mais informações, consulte a seção intitulada **especificações de exceção e noexcept**.  
  
-   Use tipos de exceção de biblioteca padrão quando elas se aplicam. Derivar tipos de exceção personalizada da [classe exception](../standard-library/exception-class1.md) hierarquia. Para obter mais informações, consulte [(NOTINBUILD) como: usar os objetos de exceção de biblioteca padrão](http://msdn.microsoft.com/pt-br/ad1fb785-ed4e-4d94-8e84-964353aed7b6).  
  
-   Não permitir exceções sair do destruidores ou funções de desalocação de memória.  
  
## <a name="exceptions-and-performance"></a>Desempenho e exceções  
 O mecanismo de exceção tem um desempenho mínimo custo se nenhuma exceção é lançada. Se uma exceção for lançada, o custo com a passagem de pilha e desenrolamento são aproximadamente comparável ao custo de uma chamada de função. Estruturas de dados adicionais são necessárias para rastrear a pilha de chamadas após um `try` bloco é inserido e instruções adicionais são necessárias para desenrolar a pilha se uma exceção é lançada. No entanto, na maioria dos cenários, o custo de desempenho e espaço de memória não é significativo. A desvantagem de exceções no desempenho provavelmente ser significativas somente em sistemas de memória muito limitada, ou no desempenho crítico faz um loop em que um erro é provável de ocorrer regularmente e o código para lidar com ele está acoplado ao código que informa. Em qualquer caso, é impossível saber o custo real de exceções sem a criação de perfil e medição. Mesmo em casos raros quando o custo é importante, você pode avaliá-lo contra a maior exatidão, facilidade de manutenção mais fácil e outras vantagens que são fornecidas por uma diretiva de exceção bem projetado.  
  
## <a name="exceptions-vs-assertions"></a>Exceções versus asserções  
 Exceções e declara dois mecanismos distintos para detectar erros de tempo de execução em um programa. Use asserções para testar condições durante o desenvolvimento do que nunca deve ser true se todo o código está correto. Não faz sentido no tratamento de erro usando uma exceção porque o erro indica que algo no código precisa ser corrigido e não representa uma condição que o programa precisa recuperar de tempo de execução. Uma declaração interrompe a execução da instrução para que você pode inspecionar o estado do programa no depurador; uma exceção continua a execução do primeiro manipulador catch apropriada. Use exceções para verificar condições de erro que podem ocorrer em tempo de execução, mesmo se o código está correto, por exemplo, "arquivo não encontrado" ou "sem"memória. Você talvez queira recuperar essas condições, mesmo se a recuperação apenas gera uma mensagem para um log e encerra o programa. Sempre verifique os argumentos para funções públicas usando exceções. Mesmo se sua função é livre de erros, você não pode ter controle total sobre os argumentos que um usuário pode passar para ele.  
  
## <a name="c-exceptions-versus-windows-seh-exceptions"></a>Exceções de C++ versus exceções SEH do Windows  
 Programas C e C++ podem usar a mecanismo (SEH) no sistema operacional Windows de manipulação de exceção estruturada. Os conceitos em SEH semelhantes aos em exceções de C++, exceto pelo fato de SEH usa o `__try`, `__except`, e `__finally` constrói, em vez de `try` e `catch`. No Visual C++, exceções do C++ são implementadas para SEH. No entanto, quando você escreve código C++, use a sintaxe de exceção do C++.  
  
 Para obter mais informações sobre o SEH, consulte [Structured Exception Handling (C/C++)](../cpp/structured-exception-handling-c-cpp.md).  
  
## <a name="exception-specifications-and-noexcept"></a>Noexcept e especificações de exceção  
 Especificações de exceção introduzidas no C++ como uma maneira de especificar as exceções que pode acionar uma função. No entanto, especificações de exceção se mostrou um problema na prática e são preteridas no padrão C + + 11 rascunho. É recomendável que você não use especificações de exceção, exceto para `throw()`, que indica que a exceção não permite nenhuma exceção de escape. Se você precisar usar as especificações de exceção do tipo `throw(`*tipo*`)`, lembre-se que [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] foge do padrão de determinadas maneiras. Para obter mais informações, consulte [especificações de exceção (acionar)](../cpp/exception-specifications-throw-cpp.md). O `noexcept` especificador é introduzido no C++ 11 como a alternativa preferida para `throw()`.  
  
## <a name="see-also"></a>Consulte também  
 [Como: Interface entre códigos excepcional e não excepcional](../cpp/how-to-interface-between-exceptional-and-non-exceptional-code.md)   
 [Bem-vindo novamente para C++](../Topic/Welcome%20Back%20to%20C++%20\(Modern%20C++\).md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)