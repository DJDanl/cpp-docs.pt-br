---
title: "Erro do Compilador C2065 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2065"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2065"
ms.assetid: 78093376-acb7-45f5-9323-5ed7e0aab1dc
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2065
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'identifier': identificador não declarada  
  
 Tipo da variável deve ser especificado em uma declaração para que possa ser usado.  Os parâmetros que usa uma função devem ser especificados em uma declaração, ou seja, protótipo antes que a função pode ser usada.  
  
 Possíveis causas:  
  
1.  O nome do identificador está incorreto.  
  
2.  Identificador usa as letras maiúsculas e minúsculas erradas.  
  
3.  Faltando aspas de fechamento após uma constante de cadeia de caracteres.  
  
4.  Você está compilando com uma versão de depuração do tempo de execução C, declarando uma variável de iterador da biblioteca C\+\+ padrão em um `for` loop e, em seguida, tentar usar essa variável de iterador fora do escopo do `for` loop.  Compilando o código da biblioteca padrão C\+\+ com uma versão de depuração do tempo de execução C implica [\/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md).  Consulte [suporte à depuração de iterador](../../standard-library/debug-iterator-support.md) para obter mais informações.  
  
5.  Você pode chamar uma função em um arquivo de cabeçalho do SDK não é suportado atualmente no ambiente de compilação.  
  
6.  A omissão necessário incluir arquivos, especialmente se você definir `VC_EXTRALEAN`, `WIN32_LEAN_AND_MEAN`, ou `WIN32_EXTRA_LEAN`.  Esses símbolos excluir alguns arquivos de cabeçalho do Windows. h e afxv\_w32.h para acelerar compila.  \(Procure no Windows. h e afxv\_w32.h para uma descrição atualizada do que é excluído\).  
  
7.  Escopo de namespace incorreta.  Por exemplo, para resolver as funções de biblioteca padrão C\+\+ e operadores que não são totalmente qualificados, você deve especificar o `std` namespace com o `using` diretiva.  O exemplo a seguir não compila porque a `using` diretiva foi comentada e `cout` é definido na `std` namespace:  
  
## Exemplo  
 O exemplo a seguir gera C2065 e mostra como corrigi\-lo.  
  
```  
// C2065.cpp  
// compile with: /EHsc  
// using namespace std;   // Uncomment this line to fix  
#include <iostream>  
int main() {  
   cout << "Hello" << endl;   // C2065  
  
   // Or try the following line instead  
   std::cout << "Hello" << std::endl;  
}  
```  
  
## Exemplo  
 Ao chamar uma função genérica, se o argumento de tipo pretendida não puderem ser deduzido dos parâmetros usados, o compilador relatará um erro.  Para obter mais informações, consulte [Generic Functions \(C\+\+\/CLI\)](../../windows/generic-functions-cpp-cli.md).  
  
 O exemplo a seguir gera C2065 e mostra como corrigi\-lo.  
  
```  
// C2065_b.cpp  
// compile with: /clr  
generic <typename ItemType>  
void G(int i) {}  
  
int main() {  
   // global generic function call  
   G<T>(10);   // C2065  
   G<int>(10);   // OK - fix with a specific type argument  
}  
```  
  
## Exemplo  
 Esse erro também pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito no Visual C\+\+ 2005: parâmetro de verificação de atributos do Visual C\+\+.  
  
 O exemplo a seguir gera C2065 e mostra como corrigi\-lo.  
  
```  
// C2065_c.cpp  
// compile with: /c  
[module(DLL, name=MyLibrary)];   // C2065  
// try the following line instead  
// [module(dll, name="MyLibrary")];  
  
[export]  
struct MyStruct {  
   int i;  
};  
```