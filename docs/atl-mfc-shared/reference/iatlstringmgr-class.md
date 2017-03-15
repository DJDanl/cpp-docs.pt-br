---
title: Classe IAtlStringMgr | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IAtlStringMgr
dev_langs:
- C++
helpviewer_keywords:
- shared classes, IAtlStringMgr
- memory, managing
- IAtlStringMgr class
ms.assetid: 722f0346-a770-4aa7-8f94-177be8dba823
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 4ff4aa01a6d30f377560962f98a5892bdcc37837
ms.lasthandoff: 02/25/2017

---
# <a name="iatlstringmgr-class"></a>Classe IAtlStringMgr
Essa classe representa a interface para um `CStringT` Gerenciador de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```
__interface IAtlStringMgr
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Alocar](#allocate)|Chame esse método para alocar uma nova estrutura de dados de cadeia de caracteres.|  
|[Clone](#clone)|Chame esse método para retornar um ponteiro para um novo Gerenciador de cadeia de caracteres para uso com outra instância do `CSimpleStringT`.|  
|[Livre](#free)|Chame esse método para liberar uma estrutura de dados de cadeia de caracteres.|  
|[GetNilString](#getnilstring)|Retorna um ponteiro para o `CStringData` objeto usado pelos objetos de cadeia de caracteres vazia.|  
|[Realocar](#reallocate)|Chame esse método para realocar uma estrutura de dados de cadeia de caracteres.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface gerencia a memória usada pelas classes de cadeia de caracteres MFC independente; como [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md), [CStringT](../../atl-mfc-shared/reference/cstringt-class.md), e [CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md).  
  
 Você também pode usar essa classe para implementar um Gerenciador de memória personalizado para sua classe de cadeia de caracteres personalizada. Para obter mais informações, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpstr.h  
  
##  <a name="a-nameallocatea--iatlstringmgrallocate"></a><a name="allocate"></a>IAtlStringMgr::Allocate  
 Aloca uma nova estrutura de dados de cadeia de caracteres.  
  
```
CStringData* Allocate(int nAllocLength,int nCharSize) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nAllocLength`  
 O número de caracteres no novo bloco de memória.  
  
 `nCharSize`  
 O tamanho (em bytes) do tipo caractere usado pelo Gerenciador de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o bloco de memória recém-alocada.  
  
> [!NOTE]
>  Não sinalizar uma falha na alocação lançando uma exceção. Em vez disso, uma falha de alocação deve ser sinalizada, retornando **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Chamar [IAtlStringMgr::Free](#free) ou [IAtlStringMgr::ReAllocate](#reallocate) para liberar a memória alocada por esse método.  
  
> [!NOTE]
>  Para obter exemplos de uso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
##  <a name="a-nameclonea--iatlstringmgrclone"></a><a name="clone"></a>IAtlStringMgr::Clone  
 Retorna um ponteiro para um novo Gerenciador de cadeia de caracteres para uso com outra instância do `CSimpleStringT`.  
  
```
IAtlStringMgr* Clone() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cópia do `IAtlStringMgr` objeto.  
  
### <a name="remarks"></a>Comentários  
 Geralmente chamada pela estrutura quando um Gerenciador de cadeia de caracteres é necessário para uma nova cadeia de caracteres. Na maioria dos casos, o **isso** ponteiro é retornado.  
  
 No entanto, se o Gerenciador de memória não oferece suporte a que está sendo usado por várias instâncias do `CSimpleStringT`, um ponteiro para um Gerenciador de cadeia de caracteres compartilháveis deve ser retornado.  
  
> [!NOTE]
>  Para obter exemplos de uso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
##  <a name="a-namefreea--iatlstringmgrfree"></a><a name="free"></a>IAtlStringMgr::Free  
 Libera uma estrutura de dados de cadeia de caracteres.  
  
```
void Free(CStringData* pData) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pData`  
 Um ponteiro para o bloco de memória para ser liberado.  
  
### <a name="remarks"></a>Comentários  
 Libera o bloco de memória especificado anteriormente alocado por [alocar](#allocate) ou [realocar](../../atl/reference/iatlmemmgr-class.md#reallocate).  
  
> [!NOTE]
>  Para obter exemplos de uso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
##  <a name="a-namegetnilstringa--iatlstringmgrgetnilstring"></a><a name="getnilstring"></a>IAtlStringMgr::GetNilString  
 Retorna um ponteiro para uma estrutura de dados de cadeia de caracteres para uma cadeia de caracteres vazia.  
  
```
CStringData* GetNilString() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `CStringData` objeto usado para representar uma cadeia de caracteres vazia.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para retornar uma representação de cadeia de caracteres vazia.  
  
> [!NOTE]
>  Ao implementar um Gerenciador de cadeia de caracteres personalizada, esta função nunca deve falhar. Você pode garantir isso incorporando uma instância de **CNilStringData** na classe do Gerenciador de cadeia de caracteres e retornar um ponteiro para essa instância.  
  
> [!NOTE]
>  Para obter exemplos de uso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
##  <a name="a-namereallocatea--iatlstringmgrreallocate"></a><a name="reallocate"></a>IAtlStringMgr::Reallocate  
 Realoca uma estrutura de dados de cadeia de caracteres.  
  
```
CStringData* Reallocate(  
 CStringData* pData,
 int nAllocLength,
 int nCharSize) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pData`  
 Ponteiro para a memória alocada anteriormente por este Gerenciador de memória.  
  
 `nAllocLength`  
 O número de caracteres no novo bloco de memória.  
  
 `nCharSize`  
 O tamanho (em bytes) do tipo caractere usado pelo Gerenciador de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o início do bloco de memória recém-alocada.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para redimensionar o bloco de memória existente especificado pelo `pData`.  
  
 Chamar [IAtlStringMgr::Free](#free) para liberar a memória alocada por esse método.  
  
> [!NOTE]
>  Para obter exemplos de uso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)



