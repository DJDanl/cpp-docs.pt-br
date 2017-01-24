---
title: "Tracking Reference Operator (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "%"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tracking references"
  - "% tracking reference [C++]"
ms.assetid: 142a7269-ab69-4b54-a6d7-833bef06228f
caps.latest.revision: 31
caps.handback.revision: 29
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tracking Reference Operator (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um *referência de rastreamento* \(`%`\) se comporta como uma referência de C\+\+ comuns \(`&`\) exceto que quando um objeto é atribuído a uma referência de rastreamento, a contagem de referência do objeto é incrementada.  
  
## Todas as Plataformas  
 Uma referência de rastreamento tem as seguintes características.  
  
-   Atribuição de um objeto em uma referência de rastreamento faz com que a contagem de referência do objeto a ser incrementado.  
  
-   Uma referência nativa \(&\) é o resultado quando você cancelar a referência um \*.  Uma referência de rastreamento \(%\) é o resultado quando você cancelar a referência de um ^.  Desde que você possui um % para um objeto, o objeto permanecerá ativo na memória.  
  
-   O ponto final \(`.`\) o operador de acesso de membro é usado para acessar um membro do objeto.  
  
-   Referências de acompanhamento são válidas para identificadores e tipos de valor \(por exemplo `String^`\).  
  
-   Uma referência de rastreamento não pode ser atribuída um valor nulo ou `nullptr` valor.  Uma referência de rastreamento pode ser reatribuída a outro objeto válido quantas vezes forem necessárias.  
  
-   Uma referência de rastreamento não pode ser usada como um operador unário de endereço de take.  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 Uma referência de rastreamento se comporta como uma referência de C\+\+ padrão, exceto que a % é a contagem de referência.  O trecho a seguir mostra como converter entre % e ^ tipos:  
  
```  
Foo^ spFoo = ref new Foo();  
Foo% srFoo = *spFoo;  
Foo^ spFoo2 = %srFoo;  
```  
  
 O exemplo a seguir mostra como passar um ^ para uma função que usa um %.  
  
```  
  
ref class Foo sealed {};  
  
    // internal or private  
    void UseFooHelper(Foo% f)  
    {  
        auto x = %f;  
    }  
  
    // public method on ABI boundary  
    void UseFoo(Foo^ f)  
    {  
        if (f != nullptr) { UseFooHelper(*f); }  
    }  
  
```  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 Em C\+\+ c\+\+ \/CLI, você pode usar uma referência de rastreamento para um identificador quando você vincula a um objeto de um tipo CLR no heap coletado como lixo.  
  
 No CLR, o valor de uma referência de rastreamento variável é atualizada automaticamente sempre que o coletor de lixo move o objeto referenciado.  
  
 Uma referência de rastreamento pode ser declarada somente na pilha.  Uma referência de rastreamento não pode ser um membro de uma classe.  
  
 Não é possível ter uma referência de C\+\+ nativa para um objeto no heap coletado como lixo.  
  
 Para obter mais informações sobre referências de monitoramento em C \+ c\+\+ \/CLI, consulte:  
  
-   [Como usar referências de monitoramento em C\+\+\/CLI](../dotnet/how-to-use-tracking-references-in-cpp-cli.md)  
  
-   [Como usar referências de monitoramento e tipos de valor](../misc/how-to-use-tracking-references-and-value-types.md)  
  
-   [Como usar referências de monitoramento e ponteiros internos](../misc/how-to-use-tracking-references-and-interior-pointers.md)  
  
-   [Como gravar funções de modelo que obtêm parâmetros nativos, de valor ou referência](../misc/how-to-write-template-functions-that-take-native-value-or-reference-parameters.md)  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo a seguir para C\+\+ c\+\+ \/CLI mostra como usar uma referência de rastreamento com tipos nativos e gerenciados.  
  
```  
// tracking_reference_1.cpp  
// compile with: /clr  
ref class MyClass {  
public:  
   int i;  
};  
  
value struct MyStruct {  
   int k;  
};  
  
int main() {  
   MyClass ^ x = ref new MyClass;  
   MyClass ^% y = x;   // tracking reference handle to reference object   
  
   int %ti = x->i;   // tracking reference to member of reference type  
  
   int j = 0;  
   int %tj = j;   // tracking reference to object on the stack  
  
   int * pi = new int[2];  
   int % ti2 = pi[0];   // tracking reference to object on native heap  
  
   int *% tpi = pi;   // tracking reference to native pointer  
  
   MyStruct ^ x2 = ref new MyStruct;  
   MyStruct ^% y2 = x2;   // tracking reference to value object  
  
   MyStruct z;  
   int %tk = z.k;   // tracking reference to member of value type  
  
   delete[] pi;  
}  
  
```  
  
 **Exemplo**  
  
 O exemplo a seguir para C\+\+ c\+\+ \/CLI mostra como associar uma referência de rastreamento para uma matriz.  
  
```  
// tracking_reference_2.cpp  
// compile with: /clr  
using namespace System;  
  
int main() {  
   array<int> ^ a = ref new array< Int32 >(5);  
   a[0] = 21;  
   Console::WriteLine(a[0]);  
   array<int> ^% arr = a;  
   arr[0] = 222;  
   Console::WriteLine(a[0]);  
}  
```  
  
 **Saída**  
  
  **21**  
 **222**