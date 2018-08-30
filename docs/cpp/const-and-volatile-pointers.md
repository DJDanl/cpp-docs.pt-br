---
title: Ponteiros const e volatile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- volatile keyword [C++], and pointers
- pointers, and const
- pointers, and volatile
- const keyword [C++], volatile pointers
ms.assetid: 0c92dc6c-400e-4342-b345-63ddfe649d7e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 52550df1ca89ec1252fc2910bf27598d51302495
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43212255"
---
# <a name="const-and-volatile-pointers"></a>Ponteiros const e volatile
O [const](../cpp/const-cpp.md) e [volátil](../cpp/volatile-cpp.md) palavras-chave alterar como os ponteiros são tratados. O **const** palavra-chave especifica que o ponteiro não pode ser modificado após a inicialização; o ponteiro é protegido contra modificações posteriores.  
  
 O **volátil** palavra-chave especifica que o valor associado com o nome que segue pode ser modificado por ações diferentes do aplicativo do usuário. Portanto, o **volátil** palavra-chave é útil para declarar objetos na memória compartilhada que pode ser acessada por vários processos ou áreas de dados globais usadas para comunicação com rotinas de serviço de interrupção.  
  
 Quando um nome é declarado como **volátil**, o compilador recarrega o valor da memória de cada vez que ele é acessado pelo programa. Isso reduz drasticamente as otimizações possíveis. No entanto, quando o estado de um objeto pode ser alterado inesperadamente, é a única maneira de assegurar o desempenho previsível do programa.  
  
 Para declarar o objeto apontado pelo ponteiro como **const** ou **volátil**, use uma declaração do formulário:  
  
```cpp 
const char *cpch;  
volatile char *vpch;  
```  
  
 Para declarar o valor do ponteiro — ou seja, o endereço real armazenado no ponteiro — como **const** ou **volátil**, use uma declaração do formulário:  
  
```cpp 
char * const pchc;  
char * volatile pchv;  
```  
  
 A linguagem C++ impede as atribuições que permitiriam a alteração de um objeto ou um ponteiro declarado como **const**. Essas atribuições removeriam as informações com as quais o objeto ou o ponteiro foi declarado, violando assim a intenção da declaração original. Considere as seguintes declarações:  
  
```cpp 
const char cch = 'A';  
char ch = 'B';  
```  
  
 Dadas as declarações anteriores de dois objetos (`cch`, do tipo **const char**, e `ch`, do tipo **char)**, as seguintes declarações/inicializações são válidas:  
  
```cpp 
const char *pch1 = &cch;  
const char *const pch4 = &cch;  
const char *pch5 = &ch;  
char *pch6 = &ch;  
char *const pch7 = &ch;  
const char *const pch8 = &ch;  
```  
  
 As seguintes declarações/inicializações são errôneas.  
  
```cpp 
char *pch2 = &cch;   // Error  
char *const pch3 = &cch;   // Error  
```  
  
 A declaração de `pch2` declara um ponteiro em que um objeto constante pode ser modificado e, portanto, não é permitida. A declaração de `pch3` Especifica que o ponteiro é constante, não o objeto; a declaração não é permitida pelo mesmo motivo o `pch2` declaração não é permitida.  
  
 As oito atribuições a seguir mostram a atribuição por ponteiro e a alteração do valor do ponteiro para as declarações anteriores; por enquanto, suponha que a inicialização estava correta para `pch1` a `pch8`.  
  
```cpp 
*pch1 = 'A';  // Error: object declared const  
pch1 = &ch;   // OK: pointer not declared const  
*pch2 = 'A';  // OK: normal pointer  
pch2 = &ch;   // OK: normal pointer  
*pch3 = 'A';  // OK: object not declared const  
pch3 = &ch;   // Error: pointer declared const  
*pch4 = 'A';  // Error: object declared const  
pch4 = &ch;   // Error: pointer declared const  
```  
  
 Ponteiros declarados como **volátil**, ou como uma mistura de **const** e **volátil**, obedecem às mesmas regras.  
  
 Ponteiros para **const** objetos geralmente são usados em declarações de função da seguinte maneira:  
  
```cpp 
errno_t strcpy_s( char *strDestination, size_t numberOfElements, const char *strSource );  
```  
  
 A instrução anterior declara uma função, [strcpy_s](../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md), onde dois dos três argumentos são do tipo ponteiro para **char**. Porque os argumentos são passados por referência e não por valor, a função seria livre para alterar `strDestination` e `strSource` se `strSource` não for declarado como **const**. A declaração de `strSource` como **const** assegura que o chamador `strSource` não pode ser alterado pela função chamada.  
  
> [!NOTE]
> Porque não há uma conversão padrão de *typename* <strong>\*</strong> para **const** *typename* <strong>\*</strong>, é permitido para passar um argumento do tipo `char *` à [strcpy_s](../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md). No entanto, o inverso não é verdadeiro; Nenhuma conversão implícita existe para remover o **const** atributo de um objeto ou ponteiro.  
  
 Um **const** ponteiro de um determinado tipo pode ser atribuído a um ponteiro do mesmo tipo. No entanto, um ponteiro que não é **const** não pode ser atribuído a um **const** ponteiro. O código a seguir mostra atribuições corretas e incorretas:  
  
```cpp 
// const_pointer.cpp  
int *const cpObject = 0;  
int *pObject;  
  
int main() {  
pObject = cpObject;  
cpObject = pObject;   // C3892  
}  
```  
  
 O exemplo a seguir mostra como declarar um objeto como const se você tiver um ponteiro para um ponteiro para um objeto.  
  
```cpp 
// const_pointer2.cpp  
struct X {  
   X(int i) : m_i(i) { }  
   int m_i;  
};  
  
int main() {  
   // correct  
   const X cx(10);  
   const X * pcx = &cx;  
   const X ** ppcx = &pcx;  
  
   // also correct  
   X const cx2(20);  
   X const * pcx2 = &cx2;  
   X const ** ppcx2 = &pcx2;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Ponteiros](../cpp/pointers-cpp.md)