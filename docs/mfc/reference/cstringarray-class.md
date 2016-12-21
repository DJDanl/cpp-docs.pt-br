---
title: "Classe de CStringArray | Microsoft Docs"
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
  - "CStringArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], cadeias de caracteres"
  - "Classe de CStringArray"
  - "matrizes de cadeia de caracteres"
  - "cadeias de caracteres [C++], coleções"
ms.assetid: 6c637e06-bba8-4c08-b0fc-cf8cb067ce34
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CStringArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Oferece suporte a matrizes de objetos [CString](../../atl-mfc-shared/using-cstring.md).  
  
## Sintaxe  
  
```  
class CStringArray : public CObject  
```  
  
## Membros  
 As funções de membro de `CStringArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md).  Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro.  Ao ver um ponteiro de `CObject` como valor retornado, substitua um objeto [CString](../../atl-mfc-shared/using-cstring.md) \(não um ponteiro [CString](../../atl-mfc-shared/using-cstring.md)\).  Ao ver um ponteiro de `CObject` como um parâmetro de função, substitua um `LPCTSTR`.  
  
 `CObject* CObArray::GetAt( int <nIndex> ) const;`  
  
 por exemplo, traduz para  
  
 `CString CStringArray::GetAt( int <nIndex> ) const;`  
  
 e  
  
 `void SetAt( int <nIndex>, CObject* <newElement> )`  
  
 traduz para  
  
 `void SetAt( int <nIndex>, LPCTSTR <newElement> )`  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CObArray::CObArray](../Topic/CObArray::CObArray.md)|Constrói uma matriz vazia.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CObArray::Add](../Topic/CObArray::Add.md)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|  
|[CObArray::Append](../Topic/CObArray::Append.md)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|  
|[CObArray::Copy](../Topic/CObArray::Copy.md)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|  
|[CObArray::ElementAt](../Topic/CObArray::ElementAt.md)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|  
|[CObArray::FreeExtra](../Topic/CObArray::FreeExtra.md)|Libera toda memória não usada acima do limite superior atual.|  
|[CObArray::GetAt](../Topic/CObArray::GetAt.md)|Retorna o valor a um determinado índice.|  
|[CObArray::GetCount](../Topic/CObArray::GetCount.md)|Obtém o número de elementos nesta matriz.|  
|[CObArray::GetData](../Topic/CObArray::GetData.md)|Permite acesso aos elementos na matriz.  Pode ser **NULO**.|  
|[CObArray::GetSize](../Topic/CObArray::GetSize.md)|Obtém o número de elementos nesta matriz.|  
|[CObArray::GetUpperBound](../Topic/CObArray::GetUpperBound.md)|Retorna o maior índice válido.|  
|[CObArray::InsertAt](../Topic/CObArray::InsertAt.md)|Insere um elemento \(ou todos os elementos em outra matriz\) em um índice especificado.|  
|[CObArray::IsEmpty](../Topic/CObArray::IsEmpty.md)|Determina se a matriz está vazia.|  
|[CObArray::RemoveAll](../Topic/CObArray::RemoveAll.md)|Remove todos os elementos dessa matriz.|  
|[CObArray::RemoveAt](../Topic/CObArray::RemoveAt.md)|Remove um elemento a um índice específico.|  
|[CObArray::SetAt](../Topic/CObArray::SetAt.md)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|  
|[CObArray::SetAtGrow](../Topic/CObArray::SetAtGrow.md)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|  
|[CObArray::SetSize](../Topic/CObArray::SetSize.md)|Define o número de elementos a ser contido nesta matriz.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CObArray::operator](../Topic/CObArray::operator.md)|Define ou obtém o elemento no índice especificado.|  
  
## Comentários  
 A `CStringArray` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos.  Se uma matriz de objetos `CString` for armazenada em um arquivo, com um operador de inserção sobrecarregado ou com a função de membro `Serialize`, cada elemento é serializado por vez.  
  
> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela.  Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada.  Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.  
  
 Se for necessário um despejo de elementos de cadeia de caracteres individuais na matriz, será necessário definir a profundidade do contexto do despejo para 1 ou maior.  
  
 Quando uma matriz `CString` é excluída ou quando seus elementos são removidos, a memória da cadeia de caracteres é liberada conforme adequado.  
  
 Para obter mais informações sobre como usar a `CStringArray`, consulte o artigo [Coleções](../../mfc/collections.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CStringArray`  
  
## Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)