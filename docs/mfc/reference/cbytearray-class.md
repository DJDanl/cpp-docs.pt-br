---
title: "Classe de CByteArray | Microsoft Docs"
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
  - "CByteArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], Byte"
  - "matrizes de bytes"
  - "Classe de CByteArray"
  - "Classes de coleção MFC, matrizes de bytes"
ms.assetid: 53d4a512-657c-4187-9609-e3f5339a78e0
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CByteArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Suporta matrizes dinâmicas de bytes.  
  
## Sintaxe  
  
```  
class CByteArray : public CObject  
```  
  
## Membros  
 As funções de membro de `CByteArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md).  Devido a essa similaridade, você pode usar a documentação de referência de `CObArray` para específicos da função de membro.  Onde quer que você verá um ponteiro de `CObject` como um ou um valor de retorno da função, substitua **BYTE**.  
  
 `CObject* CObArray::GetAt( int <nIndex> ) const;`  
  
 por exemplo, converte a  
  
 `BYTE CByteArray::GetAt( int <nIndex> ) const;`  
  
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
|[CObArray::ElementAt](../Topic/CObArray::ElementAt.md)|Retorna uma referência temporária ao byte na matriz.|  
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
 `CByteArray` inserir a macro de `IMPLEMENT_SERIAL` para oferecer suporte a serialização e a despejo de seus elementos.  Se uma matriz de bytes está armazenada em um arquivo, com o operador sobrecarregado de inserção \(**\<\<**\) ou com a função de membro de `Serialize` , cada elemento, é serializado por sua vez.  
  
> [!NOTE]
>  Antes de usar uma matriz, use `SetSize` para estabelecer o tamanho e atribuir a memória para ele.  Se você não usar `SetSize`, adicione os elementos a sua matriz freqüentemente faz com que ele manipule a ser realocada e copiado.  A realocação freqüentes e copiar e são não podem fragmentar a memória.  
  
 Se você precisar saída de depuração dos elementos individuais na matriz, você deve definir o tamanho do objeto de `CDumpContext` a 1 ou maior.  
  
 Para obter mais informações sobre como usar `CByteArray`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CByteArray`  
  
## Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CObArray](../../mfc/reference/cobarray-class.md)