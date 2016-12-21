---
title: "Classe de CObArray | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CObArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], Tipo de objeto"
  - "matrizes [C++], ponteiros"
  - "Classe de CObArray"
  - "matrizes de objetos, Classe de CObArray"
ms.assetid: 27894efd-2370-4776-9ed9-24a98492af17
caps.latest.revision: 20
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CObArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Suporta matrizes de ponteiros de `CObject` .  
  
## Sintaxe  
  
```  
class CObArray : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CObArray::CObArray](../Topic/CObArray::CObArray.md)|Constrói uma matriz vazia para ponteiros de `CObject` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CObArray::Add](../Topic/CObArray::Add.md)|Adiciona um elemento ao final da matriz; aumenta a matriz se necessário.|  
|[CObArray::Append](../Topic/CObArray::Append.md)|Acrescenta uma matriz a outra matriz; aumenta a matriz se necessário.|  
|[CObArray::Copy](../Topic/CObArray::Copy.md)|Copia uma matriz a outra matriz; aumenta a matriz se necessário.|  
|[CObArray::ElementAt](../Topic/CObArray::ElementAt.md)|Retorna uma referência temporária ao ponteiro de elemento dentro da matriz.|  
|[CObArray::FreeExtra](../Topic/CObArray::FreeExtra.md)|Qualquer libera a memória não usado acima do limite superior atual.|  
|[CObArray::GetAt](../Topic/CObArray::GetAt.md)|Retorna o valor em um índice especificado.|  
|[CObArray::GetCount](../Topic/CObArray::GetCount.md)|Obtém o número de elementos em esta matriz.|  
|[CObArray::GetData](../Topic/CObArray::GetData.md)|Permite acesso aos elementos na matriz.  Pode ser **NULO**.|  
|[CObArray::GetSize](../Topic/CObArray::GetSize.md)|Obtém o número de elementos em esta matriz.|  
|[CObArray::GetUpperBound](../Topic/CObArray::GetUpperBound.md)|Retorna o índice válido maior.|  
|[CObArray::InsertAt](../Topic/CObArray::InsertAt.md)|Insere elemento \(ou todos os elementos em outros matriz\) em um índice especificado.|  
|[CObArray::IsEmpty](../Topic/CObArray::IsEmpty.md)|Determina se a matriz está vazia.|  
|[CObArray::RemoveAll](../Topic/CObArray::RemoveAll.md)|Remove todos os elementos da matriz.|  
|[CObArray::RemoveAt](../Topic/CObArray::RemoveAt.md)|Remove um elemento em um índice específico.|  
|[CObArray::SetAt](../Topic/CObArray::SetAt.md)|Defina o valor para um índice dado; matriz não permitida crescer.|  
|[CObArray::SetAtGrow](../Topic/CObArray::SetAtGrow.md)|Defina o valor para um índice dado; aumenta a matriz se necessário.|  
|[CObArray::SetSize](../Topic/CObArray::SetSize.md)|Define o número de elementos a serem contidos em esta matriz.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CObArray::operator](../Topic/CObArray::operator.md)|Obtém ou define o elemento no índice especificado.|  
  
## Comentários  
 Essas matrizes de objetos são semelhantes às matrizes de C, mas podem dinamicamente reduz e crescer conforme necessário.  
  
 Matriz de índices sempre início na posição 0.  Você pode decidir se corrigir o limite superior ou permitir que a matriz expandir quando você adiciona elementos após o limite atual.  A memória é atribuída continuamente ao limite superior, mesmo se alguns elementos são nulos.  
  
 Em O, o tamanho de um objeto de `CObArray` é delimitado somente na memória disponível.  
  
 Como com matriz de energia AC, última hora de acesso para um elemento indexado `CObArray` são constantes e são independentes do tamanho da matriz.  
  
 `CObArray` inserir a macro de `IMPLEMENT_SERIAL` para oferecer suporte a serialização e a despejo de seus elementos.  Se uma matriz de ponteiros de `CObject` é armazenada em um arquivo, com o operador sobrecarregado insert ou com a função de membro de `Serialize` , cada elemento de `CObject` , é serializado por sua vez junto com seu índice de matriz.  
  
 Se você precisar de um despejo dos elementos individuais de `CObject` em uma matriz, você deve definir o tamanho do objeto de `CDumpContext` a 1 ou maior.  
  
 Quando um objeto de `CObArray` é excluído, ou quando seus elementos são removidos, somente os ponteiros de `CObject` são removidos, não os objetos que referenciam.  
  
> [!NOTE]
>  Antes de usar uma matriz, use `SetSize` para estabelecer o tamanho e atribuir a memória para ele.  Se você não usar `SetSize`, adicione os elementos a sua matriz freqüentemente faz com que ele manipule a ser realocada e copiado.  A realocação freqüentes e copiar e são não podem fragmentar a memória.  
  
 A derivação da classe da matriz é semelhante à derivação da lista.  Para obter detalhes sobre derivar de uma classe de lista de propósito especial, consulte o artigo [coleções](../../mfc/collections.md).  
  
> [!NOTE]
>  Você deve usar a macro de `IMPLEMENT_SERIAL` na implementação da classe derivada se você pretende serializar a matriz.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CObArray`  
  
## Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CStringArray](../../mfc/reference/cstringarray-class.md)   
 [Classe de CPtrArray](../../mfc/reference/cptrarray-class.md)   
 [Classe de CByteArray](../../mfc/reference/cbytearray-class.md)   
 [Classe de CWordArray](../../mfc/reference/cwordarray-class.md)   
 [Classe de CDWordArray](../Topic/CDWordArray%20Class.md)