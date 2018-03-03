---
title: "delegado (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- delegate_cpp
- delegate
dev_langs:
- C++
helpviewer_keywords:
- delegate keyword [C++]
ms.assetid: 03caf23d-7873-4a23-9b34-becf42aaf429
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 30fd64fd37fb30c34b5d4f5901f16143fb1cd701
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="delegate--c-component-extensions"></a>delegado (Extensões de Componentes C++)
Declara um tipo que representa um ponteiro de função.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 O tempo de execução do Windows e o common language runtime suportam a delegados.  
  
### <a name="remarks"></a>Comentários  
 `delegate`é uma palavra-chave contextual. Para obter mais informações, consulte [sensível ao contexto palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md).  
  
 Para detectar no tempo de compilação se um tipo for um representante, use o `__is_delegate()` característica de tipo. Para obter mais informações, consulte [suporte para características do tipo de compilador](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 C + + CX dá suporte a representantes com a sintaxe a seguir.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
access  
delegate  
return-type  
delegate-type-identifier  
(  
[ parameters ]  
)  
  
```  
  
### <a name="parameters"></a>Parâmetros  
 *access*  
 (opcional) A acessibilidade de delegado, que pode ser `public` (o padrão) ou `private`. O protótipo de função também pode ser qualificado com o `const` ou `volatile` palavras-chave.  
  
 *tipo de retorno*  
 O tipo de retorno do protótipo de função.  
  
 *Identificador de tipo de representante*  
 O nome do tipo delegado declarado.  
  
 *parâmetros*  
 (Opcional) Os tipos e os identificadores de protótipo de função.  
  
### <a name="remarks"></a>Comentários  
 Use o *identificador de tipo de delegado* para declarar um evento com o mesmo protótipo do representante. Para obter mais informações, consulte [delegados (C + + CX)](../cppcx/delegates-c-cx.md).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
 O common language runtime oferece suporte a representantes com a sintaxe a seguir.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
access  
delegate  
function_declaration  
  
```  
  
### <a name="parameters"></a>Parâmetros  
 *access*  
 (opcional) A acessibilidade do representante fora do assembly pode ser público ou privado.  O padrão é particular.  Dentro de uma classe, um representante pode ter qualquer acessibilidade.  
  
 *function_declaration*  
 A assinatura da função que pode ser associada ao representante. O tipo de retorno de um delegado pode ser qualquer tipo gerenciado. Por motivos de interoperabilidade, recomenda-se que o tipo de retorno de um delegado ser um tipo CLS.  
  
 Para definir um delegate não associado, o primeiro parâmetro *function_declaration* devem ser do tipo do `this` ponteiro para o objeto. 
  
### <a name="remarks"></a>Comentários  
 Delegados são multicast: o ponteiro de função"" pode ser associado a um ou mais métodos dentro de uma classe gerenciada. O **delegar** palavra-chave define um tipo de delegado multicast com assinatura de um método específico.  
  
 Um delegado também pode ser associado a um método de uma classe de valor, como um método estático.  
  
 Um delegado tem as seguintes características:  
  
-   Ele herda de **System::MulticastDelegate**.  
  
-   Ele tem um construtor que leva dois argumentos: um ponteiro para uma classe gerenciada ou **nulo** (no caso de associação a um método estático) e um método totalmente qualificado do tipo especificado.  
  
-   Tem um método chamado `Invoke`, cuja assinatura corresponde à assinatura declarada do delegado.  
  
 Quando um delegado é invocado, suas funções são chamadas na ordem em que eles foram anexados.  
  
 O valor de retorno de um delegado é o valor de retorno de sua função de membro anexada a última.  
  
 Delegados não podem ser sobrecarregados.  
  
 Delegados podem ser associados ou não associados.  
  
 Quando você cria uma instância de um delegado associado, o primeiro argumento deve ser uma referência de objeto.  O segundo argumento da instanciação de um delegado, o deve ser o endereço de um método de um objeto de classe gerenciada ou um ponteiro para um método de um tipo de valor.   O segundo argumento de uma instanciação de delegado deve nomear o método com a sintaxe de escopo de classe completo e aplicar o operador address-of.  
  
 Quando você instancia um delegate não associado, o primeiro argumento deve ser o endereço de um método de um objeto de classe gerenciada ou um ponteiro para um método de um tipo de valor.   O argumento deve nomear o método com a sintaxe de escopo de classe completo e aplique o operador de endereço.  
  
 Ao criar um delegado para uma função estática ou global, somente um parâmetro é necessário: a função (e, opcionalmente, o endereço da função).  
  
 Para obter mais informações sobre delegados, consulte  
  
-   [Como definir e usar delegados (C++/CLI)](../dotnet/how-to-define-and-use-delegates-cpp-cli.md)  
  
-   [Delegados genéricos (Visual C++)](../windows/generic-delegates-visual-cpp.md)  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo a seguir mostra como declarar e inicializar e invocar delegados.  
  
```cpp  
// mcppv2_delegate.cpp  
// compile with: /clr  
using namespace System;  
  
// declare a delegate  
public delegate void MyDel(int i);  
  
ref class A {  
public:  
   void func1(int i) {  
      Console::WriteLine("in func1 {0}", i);  
   }  
  
   void func2(int i) {  
      Console::WriteLine("in func2 {0}", i);  
   }  
  
   static void func3(int i) {  
      Console::WriteLine("in static func3 {0}", i);  
   }  
};  
  
int main () {  
   A ^ a = gcnew A;  
  
   // declare a delegate instance  
   MyDel^ DelInst;  
  
   // test if delegate is initialized  
   if (DelInst)  
      DelInst(7);  
  
   // assigning to delegate  
   DelInst = gcnew MyDel(a, &A::func1);  
  
   // invoke delegate  
   if (DelInst)  
      DelInst(8);  
  
   // add a function  
   DelInst += gcnew MyDel(a, &A::func2);  
  
   DelInst(9);  
  
   // remove a function  
   DelInst -= gcnew MyDel(a, &A::func1);  
  
   // invoke delegate with Invoke  
   DelInst->Invoke(10);  
  
   // make delegate to static function  
   MyDel ^ StaticDelInst = gcnew MyDel(&A::func3);  
   StaticDelInst(11);  
}  
```  
  
 **Saída**  
  
```Output  
in func1 8  
  
in func1 9  
  
in func2 9  
  
in func2 10  
  
in static func3 11  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)