---
title: "Classe de CUIntArray | Microsoft Docs"
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
  - "CUIntArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], indexado"
  - "Classe de CUIntArray"
  - "matrizes indexadas"
  - "INT"
  - "UINT"
  - "Tipo de dados de PALAVRAS"
ms.assetid: d71f3d8f-ef9f-4e48-9b69-7782c0e2ddf7
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CUIntArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Suporta matrizes de números inteiros sem sinal.  
  
## Sintaxe  
  
```  
class CUIntArray : public CObject  
```  
  
## Membros  
 As funções de membro de `CUIntArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md).  Devido a essa similaridade, você pode usar a documentação de referência de `CObArray` para específicos da função de membro.  Onde quer que você verá um ponteiro de `CObject` como um ou um valor de retorno da função, substitua **UINT**.  
  
 `CObject* CObArray::GetAt( int <nIndex> ) const;`  
  
 por exemplo, converte a  
  
 `UINT CUIntArray::GetAt( int <nIndex> ) const;`  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CObArray::CObArray](../Topic/CObArray::CObArray.md)|Constrói uma matriz vazia.|  
  
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
 Um inteiro sem sinal, ou **UINT**, diferem da palavra e do word compostas físico que o tamanho de **UINT** pode mudar como o ambiente operacional de destino.  **UINT** é o mesmo tamanho que uma palavra composta.  
  
 `CUIntArray` inserir a macro de [IMPLEMENT\_DYNAMIC](../Topic/IMPLEMENT_DYNAMIC.md) para oferecer suporte ao acesso do tipo em tempo de execução e o despejo a [CDumpContext](../../mfc/reference/cdumpcontext-class.md) de um objeto.  Se você precisar de um despejo dos elementos individuais de número inteiro sem sinal, você deve definir o tamanho do contexto de um despejo a 1 ou maior.  Matrizes de número inteiro sem sinal não podem ser serializadas.  
  
> [!NOTE]
>  Antes de usar uma matriz, use `SetSize` para estabelecer o tamanho e atribuir a memória para ele.  Se você não usar `SetSize`, adicione os elementos a sua matriz freqüentemente faz com que ele manipule a ser realocada e copiado.  A realocação freqüentes e copiar e são não podem fragmentar a memória.  
  
 Para obter mais informações sobre como usar `CUIntArray`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CUIntArray`  
  
## Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)