---
title: Semântica de pilha do C++ para tipos de referência | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- reference types, C++ stack semantics for
ms.assetid: 319a1304-f4a4-4079-8b84-01cec847d531
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: b3ed886d1bdeb4972122049854b5d288767aa5b8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33111348"
---
# <a name="c-stack-semantics-for-reference-types"></a>Semântica da pilha do C++ para tipos de referência
Antes do Visual C++ 2005, uma instância de um tipo de referência pode somente ser criada usando o `new` operador, que criou o objeto no lixo coletado heap. No entanto, agora você pode criar uma instância de um tipo de referência usando a mesma sintaxe que você usaria para criar uma instância de um tipo nativo na pilha. Portanto, você não precisa usar [gcnew novo ref](../windows/ref-new-gcnew-cpp-component-extensions.md) para criar um objeto do tipo de referência. E, quando o objeto sai do escopo, o compilador chama o destruidor do objeto.  
  
## <a name="remarks"></a>Comentários  
 Quando você cria uma instância de um tipo de referência usando a semântica de pilha, internamente o compilador criar a instância no heap lixo coletado (usando `gcnew`).  
  
 Quando o tipo de assinatura ou de retorno de uma função inclui uma instância de um tipo de referência por valor, a função será marcada nos metadados como que requerem tratamento especial (com modreq). Esse tratamento especial no momento é fornecido apenas pelos clientes do Visual C++. outros idiomas não dão suporte atualmente consumindo funções ou dados que usam tipos de referência criados com semântica de pilha.  
  
 Um motivo para usar `gcnew` (alocação dinâmica) em vez de pilha semântica seria se o tipo não tenha um destruidor. Além disso, usar os tipos de referência criados com semântica de pilha em assinaturas de função não seria possível se você quiser que suas funções a serem consumidos por idiomas diferentes do Visual C++.  
  
 O compilador não irá gerar um construtor de cópia para um tipo de referência. Portanto, se você definir uma função que usa um tipo de referência por valor na assinatura, você deve definir um construtor de cópia para o tipo de referência. Um construtor de cópia para um tipo de referência tem uma assinatura da seguinte forma: `R(R%){}`.  
  
 O compilador não irá gerar um operador de atribuição padrão para um tipo de referência. Um operador de atribuição permite que você crie um objeto usando a semântica de pilha e inicializá-lo com um objeto existente criado usando a semântica de pilha. Um operador de atribuição para um tipo de referência tem uma assinatura da seguinte forma: `void operator=( R% ){}`.  
  
 Se o destruidor do tipo libera recursos críticos e usar semântica de pilha para tipos de referência, você não precisa chamar explicitamente o destruidor (ou chamar `delete`). Para obter mais informações sobre destruidores em tipos de referência, consulte [destruidores e finalizadores em como: definir e consumir classes e estruturas (C + + CLI)](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).  
  
 Um operador de atribuição gerado pelo compilador seguirá as regras padrão do C++ comuns com as seguintes adições:  
  
-   Nenhum dado de não-estático membros cujo tipo é um identificador para um tipo de referência será copiada shallow (tratado como um membro de dados não estático, cujo tipo é um ponteiro).  
  
-   Qualquer membro de dados não estático, cujo tipo é que um tipo de valor será superficial copiado.  
  
-   Qualquer membro de dados não estático, cujo tipo é uma instância de um tipo de referência invocará uma chamada para o construtor de cópia do tipo de referência.  
  
 O compilador também fornece um `%` operador unário para converter uma instância de um tipo de referência criado usando a semântica de pilha e seu tipo subjacente do identificador.  
  
 Os seguintes tipos de referência não estão disponíveis para uso com a semântica de pilha:  
  
-   [delegate (Extensões de componentes do C++)](../windows/delegate-cpp-component-extensions.md)  
  
-   [Matrizes](../windows/arrays-cpp-component-extensions.md)  
  
-   <xref:System.String>  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 O exemplo de código a seguir mostra como declarar as instâncias de tipos de referência com semântica de pilha, como o operador de atribuição e cópia construtor funciona e como inicializar uma referência de rastreamento com o tipo de referência criado usando a semântica de pilha.  
  
### <a name="code"></a>Código  
  
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
  
### <a name="output"></a>Saída  
  
```  
98  
98  
98  
13  
13  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)