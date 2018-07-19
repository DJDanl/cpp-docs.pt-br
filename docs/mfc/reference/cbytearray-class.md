---
title: Classe CByteArray | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CByteArray
- AFXCOLL/CByteArray
- AFXCOLL/CObArray::CObArray
- AFXCOLL/CObArray::Add
- AFXCOLL/CObArray::Append
- AFXCOLL/CObArray::Copy
- AFXCOLL/CObArray::ElementAt
- AFXCOLL/CObArray::FreeExtra
- AFXCOLL/CObArray::GetAt
- AFXCOLL/CObArray::GetCount
- AFXCOLL/CObArray::GetData
- AFXCOLL/CObArray::GetSize
- AFXCOLL/CObArray::GetUpperBound
- AFXCOLL/CObArray::InsertAt
- AFXCOLL/CObArray::IsEmpty
- AFXCOLL/CObArray::RemoveAll
- AFXCOLL/CObArray::RemoveAt
- AFXCOLL/CObArray::SetAt
- AFXCOLL/CObArray::SetAtGrow
- AFXCOLL/CObArray::SetSize
dev_langs:
- C++
helpviewer_keywords:
- CObArray [MFC], CObArray
- CObArray [MFC], Add
- CObArray [MFC], Append
- CObArray [MFC], Copy
- CObArray [MFC], ElementAt
- CObArray [MFC], FreeExtra
- CObArray [MFC], GetAt
- CObArray [MFC], GetCount
- CObArray [MFC], GetData
- CObArray [MFC], GetSize
- CObArray [MFC], GetUpperBound
- CObArray [MFC], InsertAt
- CObArray [MFC], IsEmpty
- CObArray [MFC], RemoveAll
- CObArray [MFC], RemoveAt
- CObArray [MFC], SetAt
- CObArray [MFC], SetAtGrow
- CObArray [MFC], SetSize
ms.assetid: 53d4a512-657c-4187-9609-e3f5339a78e0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 22e138b586070a0e47ffa399d2c76d086fd4b951
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37335848"
---
# <a name="cbytearray-class"></a>Classe CByteArray
Dá suporte a matrizes dinâmicas de bytes.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CByteArray : public CObject  
```  
  
## <a name="members"></a>Membros  
 As funções membro da `CByteArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro. Ao ver um `CObject` ponteiro como um parâmetro de função ou um valor de retorno, substitua um BYTE.  
  
 `CObject* CObArray::GetAt( int <nIndex> ) const;`  
  
 por exemplo, traduz para  
  
 `BYTE CByteArray::GetAt( int <nIndex> ) const;`  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CObArray::CObArray](../../mfc/reference/cobarray-class.md#cobarray)|Constrói uma matriz vazia.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CObArray::Add](../../mfc/reference/cobarray-class.md#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|  
|[CObArray::Append](../../mfc/reference/cobarray-class.md#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|  
|[CObArray::Copy](../../mfc/reference/cobarray-class.md#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|  
|[CObArray::ElementAt](../../mfc/reference/cobarray-class.md#elementat)|Retorna uma referência temporária para o byte dentro da matriz.|  
|[CObArray::FreeExtra](../../mfc/reference/cobarray-class.md#freeextra)|Libera toda memória não usada acima do limite superior atual.|  
|[CObArray::GetAt](../../mfc/reference/cobarray-class.md#getat)|Retorna o valor a um determinado índice.|  
|[CObArray::GetCount](../../mfc/reference/cobarray-class.md#getcount)|Obtém o número de elementos nesta matriz.|  
|[CObArray::GetData](../../mfc/reference/cobarray-class.md#getdata)|Permite acesso aos elementos na matriz. Pode ser NULL.|  
|[CObArray::GetSize](../../mfc/reference/cobarray-class.md#getsize)|Obtém o número de elementos nesta matriz.|  
|[CObArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound)|Retorna o maior índice válido.|  
|[CObArray::InsertAt](../../mfc/reference/cobarray-class.md#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|  
|[CObArray::IsEmpty](../../mfc/reference/cobarray-class.md#isempty)|Determina se a matriz está vazia.|  
|[CObArray::RemoveAll](../../mfc/reference/cobarray-class.md#removeall)|Remove todos os elementos dessa matriz.|  
|[CObArray::RemoveAt](../../mfc/reference/cobarray-class.md#removeat)|Remove um elemento a um índice específico.|  
|[CObArray::SetAt](../../mfc/reference/cobarray-class.md#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|  
|[CObArray::SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|  
|[CObArray::SetSize](../../mfc/reference/cobarray-class.md#setsize)|Define o número de elementos a ser contido nesta matriz.|  
  
### <a name="public-operators"></a>Operadores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[[CObArray::operator]](../../mfc/reference/cobarray-class.md#operator_at)|Define ou obtém o elemento no índice especificado.|  
  
## <a name="remarks"></a>Comentários  
 `CByteArray` incorpora a macro IMPLEMENT_SERIAL para dar suporte à serialização e despejo de seus elementos. Se uma matriz de bytes é armazenada em um arquivo, com a inserção sobrecarregada ( **<<**) operador ou com o `Serialize` função de membro, cada elemento é, por sua vez, serializado.  
  
> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.  
  
 Se você precisa depurar a saída de elementos individuais na matriz, você deve definir a profundidade do `CDumpContext` objeto a ser 1 ou maior.  
  
 Para obter mais informações sobre como usar `CByteArray`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CByteArray`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** & amp;lt;1}afxcoll.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CObArray](../../mfc/reference/cobarray-class.md)
