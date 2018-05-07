---
title: Declaração de uma matriz CLR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- array keyword [C++]
ms.assetid: 36a8883c-2663-43f0-a90c-28f27035e036
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 8d8b2a5d348887d56a1221a5a9125449e5356b9f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="declaration-of-a-clr-array"></a>Declaração de uma matriz CLR
A sintaxe para declarar, instanciar e inicializar uma matriz gerenciada foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 A declaração de um objeto de matriz CLR no Managed Extensions era uma extensão da declaração de matriz padrão no qual um `__gc` palavra-chave foi colocado entre o nome do objeto de matriz e sua dimensão possivelmente preenchido por vírgulas, como o seguinte par de Exemplos:  
  
```  
void PrintValues( Object* myArr __gc[]);  
void PrintValues( int myArr __gc[,,]);  
```  
  
 Isso foi simplificado na nova sintaxe, em que usamos uma declaração de tipo de modelo semelhante à biblioteca padrão C++ `vector` declaração. O primeiro parâmetro indica o tipo de elemento. O segundo parâmetro especifica a dimensão da matriz (com um valor padrão de 1, várias dimensões de forma que apenas exigem um segundo argumento). O próprio objeto de matriz é um identificador de rastreamento e portanto deve ser fornecido um hat. Se o tipo de elemento também é um tipo de referência, ela também exige um hat. Por exemplo, o exemplo acima, quando expresso em nova sintaxe, terá a seguinte aparência:  
  
```  
void PrintValues( array<Object^>^ myArr );  
void PrintValues( array<int,3>^ myArr );  
```  
  
 Como um tipo de referência é um identificador de rastreamento em vez de um objeto, é possível especificar uma matriz CLR como o tipo de retorno de uma função. (Por outro lado, não é possível especificar a matriz nativa como o tipo de retorno de uma função.) A sintaxe para fazer isso no Managed Extensions foi um pouco não intuitivos. Por exemplo:  
  
```  
Int32 f() [];  
int GetArray() __gc[];  
```  
  
 No Visual C++, a declaração é muito mais simples. Por exemplo,  
  
```  
array<Int32>^ f();  
array<int>^ GetArray();  
```  
  
 Há suporte para a inicialização de forma abreviada de uma matriz gerenciada local ambas as versões do idioma. Por exemplo:  
  
```  
int GetArray() __gc[] {  
   int a1 __gc[] = { 1, 2, 3, 4, 5 };  
   Object* myObjArray __gc[] = {   
      __box(26), __box(27), __box(28), __box(29), __box(30)  
   };  
   return a1;  
}  
```  
  
 consideravelmente é simplificada na nova sintaxe (Observe que, como conversão boxing é implícito na sintaxe de novo, o `__box` operador foi eliminado - consulte [tipos de valor e seus comportamentos (C + + CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md) para obter uma discussão):  
  
```  
array<int>^ GetArray() {  
   array<int>^ a1 = {1,2,3,4,5};  
   array<Object^>^ myObjArray = {26,27,28,29,30};  
   return a1;  
}  
```  
  
 Como uma matriz é um tipo de referência do CLR, a declaração de cada objeto de matriz é um identificador de rastreamento. Portanto, os objetos de matriz devem ser alocados no heap CLR. (A notação abreviada oculta a alocação de heap gerenciado.) Aqui está a forma explícita de uma inicialização de objeto de matriz em extensões gerenciadas:  
  
```  
Object* myArray[] = new Object*[2];  
String* myMat[,] = new String*[4,4];  
```  
  
 Sob a nova sintaxe, o `new` expressão é substituída pelo `gcnew`. Os tamanhos de dimensão são passados como parâmetros para o `gcnew` expressão, da seguinte maneira:  
  
```  
array<Object^>^ myArray = gcnew array<Object^>(2);  
array<String^,2>^ myMat = gcnew array<String^,2>(4,4);  
```  
  
 Na sintaxe de novo, uma lista de inicialização explícita pode seguir o `gcnew` expressão; isso não era suportado em extensões gerenciadas. Por exemplo:  
  
```  
// explicit initialization list following gcnew   
// was not supported in Managed Extensions  
array<Object^>^ myArray =   
   gcnew array<Object^>(4){ 1, 1, 2, 3 };  
```  
  
## <a name="see-also"></a>Consulte também  
 [Tipos gerenciados (C + + CL)](../dotnet/managed-types-cpp-cl.md)   
 [Matrizes](../windows/arrays-cpp-component-extensions.md)