---
title: Classe CStringData | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CStringData
- ATLSIMPSTR/ATL::CStringData
- ATLSIMPSTR/ATL::AddRef
- ATLSIMPSTR/ATL::data
- ATLSIMPSTR/ATL::IsLocked
- ATLSIMPSTR/ATL::IsShared
- ATLSIMPSTR/ATL::Lock
- ATLSIMPSTR/ATL::Release
- ATLSIMPSTR/ATL::Unlock
- ATLSIMPSTR/ATL::nAllocLength
- ATLSIMPSTR/ATL::nDataLength
- ATLSIMPSTR/ATL::nRefs
- ATLSIMPSTR/ATL::pStringMgr
dev_langs:
- C++
helpviewer_keywords:
- CStringData class
- shared classes, CStringData
ms.assetid: 4e31b5ca-3dbe-4fd5-b692-8211fbfb2593
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 187892b74536de47079324d90bb21b2569e00498
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32363565"
---
# <a name="cstringdata-class"></a>Classe CStringData
Essa classe representa os dados de um objeto de cadeia de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct CStringData
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AddRef](#addref)|Incrementa a contagem de referência do objeto de dados de cadeia de caracteres.|  
|[data](#data)|Recupera os dados de caractere de um objeto de cadeia de caracteres.|  
|[IsLocked](#islocked)|Determina se o buffer do objeto de cadeia de caracteres associada está bloqueado.|  
|[IsShared](#isshared)|Determina se o buffer do objeto de cadeia de caracteres associada é compartilhado no momento.|  
|[bloqueio](#lock)|Bloqueia o buffer do objeto de cadeia de caracteres associada.|  
|[Versão](#release)|Libera o objeto de cadeia de caracteres especificada.|  
|[desbloquear](#unlock)|Libera o buffer do objeto de cadeia de caracteres associada.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[nAllocLength](#nalloclength)|Comprimento dos dados alocados em `XCHAR`s (não incluindo terminação nula)|  
|[nDataLength](#ndatalength)|Comprimento de dados usados atualmente em `XCHAR`s (não incluindo terminação nula)|  
|[nRefs](#nrefs)|A contagem de referência atual do objeto.|  
|[pStringMgr](#pstringmgr)|Um ponteiro para o Gerenciador de cadeia de caracteres deste objeto de cadeia de caracteres.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe deve ser usada somente por desenvolvedores implementar gerenciadores de cadeia de caracteres personalizada. Para obter mais informações sobre gerenciadores de cadeia de caracteres personalizada, consulte [CStringT e gerenciamento de memória](../../atl-mfc-shared/memory-management-with-cstringt.md)  
  
 Essa classe encapsula vários tipos de informações e dados associados a um objeto de cadeia de caracteres superior, como [CStringT](../../atl-mfc-shared/reference/cstringt-class.md), [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md), ou [CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md) objetos. Cada objeto de cadeia de caracteres superior contém um ponteiro para seu associado `CStringData` objeto, permitindo que vários objetos de cadeia de caracteres apontar para o mesmo objeto de dados de cadeia de caracteres. Essa relação é representada pela contagem de referência ( `nRefs`) da `CStringData` objeto.  
  
> [!NOTE]
>  Em alguns casos, um tipo de cadeia de caracteres (como **CFixedString**) não compartilharão um objeto de dados de cadeia de caracteres com mais de um objeto de cadeia de caracteres superior. Para obter mais informações sobre isso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
 Esses dados são compostos de:  
  
-   O Gerenciador de memória (do tipo [IAtlStringMgr](../../atl-mfc-shared/reference/iatlstringmgr-class.md)) da cadeia de caracteres.  
  
-   O comprimento atual ( [nDataLength](#ndatalength)) da cadeia de caracteres.  
  
-   O tamanho alocado ( [nAllocLength](#nalloclength)) da cadeia de caracteres. Por motivos de desempenho, pode ser diferente do que o comprimento da cadeia de caracteres  
  
-   A contagem de referência atual ( [nRefs](#nrefs)) da `CStringData` objeto. Esse valor é usado para determinar quantos objetos de cadeia de caracteres estão compartilhando o mesmo `CStringData` objeto.  
  
-   O buffer de caractere real ( [dados](#data)) da cadeia de caracteres.  
  
    > [!NOTE]
    >  O buffer de caractere real do objeto string é alocado pelo Gerenciador de cadeia de caracteres e é acrescentado ao `CStringData` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpstr.h  
  
##  <a name="addref"></a>  CStringData::AddRef  
 Incrementa a contagem de referência do objeto de cadeia de caracteres.  
  
```
void AddRef() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Incrementa a contagem de referência do objeto de cadeia de caracteres.  
  
> [!NOTE]
>  Chame este método em uma cadeia de caracteres com uma contagem de referência negativo, pois uma contagem negativa indica que o buffer de cadeia de caracteres está bloqueado.  
  
##  <a name="data"></a>  CStringData::data  
 Retorna um ponteiro para o buffer de caracteres de um objeto de cadeia de caracteres.  
  
```
void* data() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o buffer de caracteres do objeto de cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para retornar o buffer de caractere atual do objeto de cadeia de caracteres associada.  
  
> [!NOTE]
>  Esse buffer não está alocado pelo `CStringData` objeto mas pelo Gerenciador de cadeia de caracteres quando necessário. Quando alocados, o buffer é anexado ao objeto de dados de cadeia de caracteres.  
  
##  <a name="islocked"></a>  CStringData::IsLocked  
 Determina se o buffer de caracteres está bloqueado.  
  
```
bool IsLocked() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o buffer estiver bloqueada; caso contrário **false**.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para determinar se o buffer de caracteres de um objeto de cadeia de caracteres está bloqueado no momento.  
  
##  <a name="isshared"></a>  CStringData::IsShared  
 Determina se o buffer de caractere é compartilhado.  
  
```
bool IsShared() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o buffer for compartilhada; caso contrário **false**.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para determinar se o buffer de caracteres de um objeto de dados de cadeia de caracteres no momento é compartilhado entre vários objetos de cadeia de caracteres.  
  
##  <a name="lock"></a>  CStringData::Lock  
 Bloqueia o buffer de caracteres do objeto de cadeia de caracteres associada.  
  
```
void Lock() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para bloquear o buffer de caracteres do objeto de dados de cadeia de caracteres. Bloqueando e desbloqueando é usado quando o acesso direto ao buffer de caractere é exigido pelo desenvolvedor. Um bom exemplo de bloqueio é demonstrado pelo [LockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [UnlockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) métodos de `CSimpleStringT`.  
  
> [!NOTE]
>  Um buffer de caracteres só pode ser bloqueado se o buffer não é compartilhado entre os objetos de cadeia de caracteres mais alto.  
  
##  <a name="nalloclength"></a>  CStringData::nAllocLength  
 Comprimento do buffer alocado de caractere.  
  
```
int nAllocLength;
```  
  
### <a name="remarks"></a>Comentários  
 Armazena o comprimento do buffer de dados alocados em `XCHAR`s (não incluindo terminação nula).  
  
##  <a name="ndatalength"></a>  CStringData::nDataLength  
 Tamanho atual do objeto de cadeia de caracteres.  
  
```
int nDataLength;
```  
  
### <a name="remarks"></a>Comentários  
 Armazena o comprimento dos dados atualmente em uso no `XCHAR`s (não incluindo terminação nula).  
  
##  <a name="nrefs"></a>  CStringData::nRefs  
 Contagem de referência do objeto de dados de cadeia de caracteres.  
  
```
long nRefs;
```  
  
### <a name="remarks"></a>Comentários  
 Armazena a contagem de referência do objeto de dados de cadeia de caracteres. Essa contagem indica o número de objetos de cadeia de caracteres maior que estão associados ao objeto de dados de cadeia de caracteres. Um valor negativo indica que o objeto de dados de cadeia de caracteres está bloqueado no momento.  
  
##  <a name="pstringmgr"></a>  CStringData::pStringMgr  
 O Gerenciador de memória do objeto de cadeia de caracteres associada.  
  
```
IAtlStringMgr* pStringMgr;
```  
  
### <a name="remarks"></a>Comentários  
 Armazena o Gerenciador de memória para o objeto de cadeia de caracteres associada. Para obter mais informações sobre gerenciadores de memória e cadeias de caracteres, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
##  <a name="release"></a>  CStringData::Release  
 Diminui a contagem de referência do objeto de dados de cadeia de caracteres.  
  
```
void Release() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função para decrementar a contagem de referência, liberando o `CStringData` estrutura se a contagem de referência atinge zero. Isso geralmente ocorre quando um objeto de cadeia de caracteres é excluído e, portanto, não precisa mais referenciar o objeto de dados de cadeia de caracteres.  
  
 Por exemplo, o código a seguir poderia chamar `CStringData::Release` para o objeto de dados de cadeia de caracteres associado `str1`:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#104](../../atl-mfc-shared/codesnippet/cpp/cstringdata-class_1.cpp)]  
  
##  <a name="unlock"></a>  CStringData::Unlock  
 Desbloqueia o buffer de caracteres do objeto de cadeia de caracteres associada.  
  
```
void Unlock() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para desbloquear o buffer de caracteres do objeto de dados de cadeia de caracteres. Depois que um buffer está desbloqueado, ser compartilhada e pode ser referência contada.  
  
> [!NOTE]
>  Cada chamada para `Lock` devem ser correspondentes por uma chamada correspondente para `Unlock`.  
  
 Bloqueando e desbloqueando é usado quando o desenvolvedor deve assegurar que os dados de cadeia de caracteres não seja compartilhada. Um bom exemplo de bloqueio é demonstrado pelo [LockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [UnlockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) métodos de `CSimpleStringT`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)


