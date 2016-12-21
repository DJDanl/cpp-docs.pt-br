---
title: "Sem&#226;ntica da pilha do C++ para tipos de refer&#234;ncia | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tipos de referência, semântica de pilha C++ para"
ms.assetid: 319a1304-f4a4-4079-8b84-01cec847d531
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sem&#226;ntica da pilha do C++ para tipos de refer&#234;ncia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Antes do Visual C\+\+ 2005, uma instância de um tipo de referência só pode ser criada usando o operador de `new` , que criou o objeto no heap coletado lixo.  No entanto, agora você pode criar uma instância de um tipo de referência usando a mesma sintaxe que você usaria para criar uma instância de um tipo nativo na pilha.  Assim, você não precisa usar [ref new, gcnew](../windows/ref-new-gcnew-cpp-component-extensions.md) para criar um objeto de tipo de referência.  Quando o objeto e sair do escopo, o compilador chama o destruidor do objeto.  
  
## Comentários  
 Quando você cria uma instância de um tipo de referência usando a semântica da pilha, o compilador cria internamente a instância no heap coletado lixo \(usando `gcnew`\).  
  
 Quando a assinatura ou o tipo de retorno de uma função incluem uma instância de um tipo de referência do valor, a função será marcada nos metadados como a exigência de manipulação especial \(com modreq\).  Esse tratamento especial é fornecida atualmente apenas pelos clientes do Visual C\+\+; outros idiomas não dão suporte a funções ou atualmente consumir dados que os tipos de referência de uso criados com a semântica da pilha.  
  
 Uma razão para usar `gcnew` \(alocação dinâmica\) em vez da semântica da pilha será se o tipo não tem nenhum destruidor.  Além disso, usar os tipos de referência criados com a semântica da pilha em assinaturas de função não será possível se você deseja suas funções serem consumidas por idiomas diferentes do Visual C\+\+.  
  
 O compilador não gerará um construtor de cópia para um tipo de referência.  Em virtude disso, se você definir uma função que usa uma referência de digitar o valor na assinatura, você deve definir um construtor de cópia para o tipo de referência.  Um construtor de cópia para um tipo de referência tem uma assinatura da seguinte forma: `R(R%){}`.  
  
 O compilador não gerará um operador de atribuição padrão para um tipo de referência.  Um operador de atribuição permite que você crie um objeto usando a semântica da pilha e para inicializá\-lo a um objeto existente criado com a semântica da pilha.  Um operador de atribuição de um tipo de referência tem uma assinatura da seguinte forma: `void operator=( R% ){}`.  
  
 Se o seu tipo destruidor do libera recursos críticos e semântica da pilha de uso para tipos de referência, você não precisa chamar explicitamente o destruidor \(ou chame `delete`\).  Para obter mais informações sobre os destruidores em tipos de referência, consulte [Destruidores e finalizadores em Visual C\+\+](../misc/destructors-and-finalizers-in-visual-cpp.md).  
  
 Um operador de atribuição completo gerado segue as regras comuns padrão do C\+\+ com as adições a seguir:  
  
-   Todos os membros de dados que não sejam estáticos cujo tipo é um identificador em um tipo de referência rasos serão copiados \(tratado como um membro de dados que não sejam estáticos cujo tipo é um ponteiro\).  
  
-   O membro all de dados que não sejam estáticos cujo tipo é de um tipo de valor será copiado shallow.  
  
-   O membro all de dados que não sejam estáticos cujo tipo é uma instância de um tipo de referência invocará uma chamada para o construtor de cópia do tipo de referência.  
  
 O compilador também fornece um operador unário de `%` para converter uma instância de um tipo de referência criado com a semântica da pilha ao seu tipo subjacente do identificador.  
  
 Os seguintes tipos de referência não estão disponíveis para uso com semântica da pilha:  
  
-   [delegado](../windows/delegate-cpp-component-extensions.md)  
  
-   [Arrays](../windows/arrays-cpp-component-extensions.md)  
  
-   <xref:System.String>  
  
## Exemplo  
  
### Descrição  
 O exemplo de código mostra como declarar instâncias de tipos de referência com semântica da pilha, como o construtor do operador de atribuição e de cópia, e como inicializar uma referência de controle com o tipo de referência criado com a semântica da pilha.  
  
### Código  
  
```  
// stack_semantics_for_reference_types.cpp  
// compile with: /clr  
ref class R {  
public:  
   int i;  
   R(){}  
  
   // assignment operator  
   void operator=(R% r) {  
      i = r.i;  
   }  
  
   // copy constructor  
   R(R% r) : i(r.i) {}  
};  
  
void Test(R r) {}   // requires copy constructor  
  
int main() {  
   R r1;  
   r1.i = 98;  
  
   R r2(r1);   // requires copy constructor  
   System::Console::WriteLine(r1.i);  
   System::Console::WriteLine(r2.i);  
  
   // use % unary operator to convert instance using stack semantics  
   // to its underlying handle  
   R ^ r3 = %r1;  
   System::Console::WriteLine(r3->i);  
  
   Test(r1);  
  
   R r4;  
   R r5;  
   r5.i = 13;  
   r4 = r5;   // requires a user-defined assignment operator  
   System::Console::WriteLine(r4.i);  
  
   // initialize tracking reference  
   R % r6 = r4;  
   System::Console::WriteLine(r6.i);  
}  
```  
  
### Saída  
  
```  
98  
98  
98  
13  
13  
```  
  
## Consulte também  
 [Classes and Structs](../windows/classes-and-structs-cpp-component-extensions.md)