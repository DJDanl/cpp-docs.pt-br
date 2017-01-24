---
title: "Classe de CWordArray | Microsoft Docs"
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
  - "CWordArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], indexado"
  - "Classe de CWordArray"
  - "matrizes indexadas"
  - "INT"
  - "UINT"
  - "Tipo de dados de PALAVRAS"
ms.assetid: 2ba2c194-2c6c-40ff-9db4-e9dbe57e1f57
caps.latest.revision: 26
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWordArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Suporta matrizes de palavras de 16 bits.  
  
## Sintaxe  
  
```  
class CWordArray : public CObject  
```  
  
## Membros  
 As funções de membro de `CWordArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md).  Devido a essa similaridade, você pode usar a documentação de referência de `CObArray` para específicos da função de membro.  Onde quer que você verá um ponteiro de [CObject](../Topic/CObject%20Class.md) como um ou um valor de retorno da função, substitua **PALAVRA**.  
  
 `CObject* CObArray::GetAt( int <nIndex> ) const;`  
  
 por exemplo, converte a  
  
 `WORD CWordArray::GetAt( int <nIndex> ) const;`  
  
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
 `CWordArray` inserir a macro de [IMPLEMENT\_SERIAL](../Topic/IMPLEMENT_SERIAL.md) para oferecer suporte a serialização e a despejo de seus elementos.  Se uma matriz do word é armazenada em um arquivo, com um operador sobrecarregado insert ou com a função de membro de [CObject::Serialize](../Topic/CObject::Serialize.md) , cada elemento, é serializado por sua vez.  
  
> [!NOTE]
>  Antes de usar uma matriz, use `SetSize` para estabelecer o tamanho e atribuir a memória para ele.  Se você não usar `SetSize`, adicione os elementos a sua matriz freqüentemente faz com que ele manipule a ser realocada e copiado.  A realocação freqüentes e copiar e são não podem fragmentar a memória.  
  
 Se você precisar de um despejo dos elementos individuais na matriz, você deve definir o tamanho do contexto de um despejo a 1 ou maior.  
  
 Para obter mais informações sobre como usar `CWordArray`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CWordArray`  
  
## Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## Consulte também  
 [O exemplo COLETA MFC](../../top/visual-cpp-samples.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)