---
title: C2065 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2065
dev_langs:
- C++
helpviewer_keywords:
- C2065
ms.assetid: 78093376-acb7-45f5-9323-5ed7e0aab1dc
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: 81686df4727ab2b3d5af749174a42016e8443e70
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2065"></a>C2065 de erro do compilador
'identifier': identificador não declarado  
  
 Tipo de variável deve ser especificado em uma declaração antes que ele pode ser usado. Os parâmetros que usa uma função devem ser especificados em uma declaração, ou seja, protótipo antes que a função pode ser usada.  
  
 Possíveis causas:  
  
1.  Nome do identificador está incorreto.  
  
2.  Identificador usa as letras maiusculas e minúsculas erradas.  
  
3.  Faltando aspas de fechamento após uma constante de cadeia de caracteres.  
  
4.  Você está compilando com uma versão de depuração do tempo de execução C, declarando uma variável de iterador de biblioteca padrão C++ em uma `for` loop e, em seguida, tentar usar essa variável de iterador fora do escopo do `for` loop. Compilando o código da biblioteca padrão C++ com uma versão de depuração do tempo de execução C implica [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md).  Consulte [suporte a iterador de depuração](../../standard-library/debug-iterator-support.md) para obter mais informações.  
  
5.  Você pode chamar uma função em um arquivo de cabeçalho do SDK não é suportado atualmente no ambiente de compilação.  
  
6.  A omissão necessário incluir arquivos, especialmente se você definir `VC_EXTRALEAN`, `WIN32_LEAN_AND_MEAN`, ou `WIN32_EXTRA_LEAN`. Esses símbolos excluir alguns arquivos de cabeçalho do Windows. h e afxv_w32.h para acelerar compila. (Veja no Windows. h e afxv_w32.h para uma descrição atualizada do que é excluído).  
  
7.  Escopo de namespace incorreta. Por exemplo, para resolver as funções de biblioteca padrão C++ e operadores que não são totalmente qualificados, você deve especificar o `std` namespace com o `using` diretiva. O exemplo a seguir não compila porque o `using` diretiva é comentada e `cout` é definido na `std` namespace:  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2065 e mostra como corrigi-lo.  
  
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
  
## <a name="example"></a>Exemplo  
 Ao chamar uma função genérica, se o argumento de tipo pretendida não pode ser deduzido dos parâmetros usados, o compilador relatará um erro. Para obter mais informações, consulte [funções genéricas (C + + / CLI)](../../windows/generic-functions-cpp-cli.md).  
  
 O exemplo a seguir gera C2065 e mostra como corrigi-lo.  
  
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
  
## <a name="example"></a>Exemplo  
 Esse erro também pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito no Visual C++ 2005: parâmetro procurando atributos do Visual C++.  
  
 O exemplo a seguir gera C2065 e mostra como corrigi-lo.  
  
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
