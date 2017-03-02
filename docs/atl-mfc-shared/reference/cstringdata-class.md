---
title: Classe CStringData | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CStringData
dev_langs:
- C++
helpviewer_keywords:
- CStringData class
- shared classes, CStringData
ms.assetid: 4e31b5ca-3dbe-4fd5-b692-8211fbfb2593
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: b7dfebebbec7acc774fa2e63ab9fafed788f679a
ms.lasthandoff: 02/25/2017

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
|[IsLocked](#islocked)|Determina se o buffer do objeto de cadeia de caracteres associado será bloqueado.|  
|[IsShared](#isshared)|Determina se o buffer do objeto de cadeia de caracteres associado estiver sendo compartilhado.|  
|[Bloqueio](#lock)|Bloqueia o buffer do objeto de cadeia de caracteres associado.|  
|[Versão](#release)|Libera o objeto de cadeia de caracteres especificada.|  
|[Desbloquear](#unlock)|Desbloqueia o buffer do objeto de cadeia de caracteres associado.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[nAllocLength](#nalloclength)|Comprimento de dados alocados nos `XCHAR`s (não incluindo a terminação nula)|  
|[nDataLength](#ndatalength)|Comprimento dos dados atualmente em uso em `XCHAR`s (não incluindo a terminação nula)|  
|[nRefs](#nrefs)|A contagem de referência atual do objeto.|  
|[pStringMgr](#pstringmgr)|Um ponteiro para o Gerenciador de cadeia de caracteres deste objeto de cadeia de caracteres.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe só deve ser usada por desenvolvedores implementar gerenciadores de cadeia de caracteres personalizada. Para obter mais informações sobre gerenciadores de cadeia de caracteres personalizada, consulte [CStringT e gerenciamento de memória](../../atl-mfc-shared/memory-management-with-cstringt.md)  
  
 Essa classe encapsula vários tipos de informações e dados associados a um objeto de cadeia de caracteres superior, como [CStringT](../../atl-mfc-shared/reference/cstringt-class.md), [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md), ou [CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md) objetos. Cada objeto de cadeia de caracteres superior contém um ponteiro para seus associados `CStringData` objeto, permitindo que vários objetos de cadeia de caracteres apontar para o mesmo objeto de dados de cadeia de caracteres. Essa relação é representada pela contagem de referência ( `nRefs`) do `CStringData` objeto.  
  
> [!NOTE]
>  Em alguns casos, um tipo de cadeia de caracteres (como **CFixedString**) não compartilhará um objeto de dados de cadeia de caracteres com mais de um objeto de cadeia de caracteres maior. Para obter mais informações sobre isso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
 Esses dados são compostos de:  
  
-   O Gerenciador de memória (do tipo [IAtlStringMgr](../../atl-mfc-shared/reference/iatlstringmgr-class.md)) da cadeia de caracteres.  
  
-   O comprimento atual ( [nDataLength](#ndatalength)) da cadeia de caracteres.  
  
-   O tamanho alocado ( [nAllocLength](#nalloclength)) da cadeia de caracteres. Por motivos de desempenho, pode ser diferente do que o comprimento da cadeia de caracteres  
  
-   A contagem de referência atual ( [nRefs](#nrefs)) do `CStringData` objeto. Esse valor é usado para determinar quantos objetos de cadeia de caracteres estiver compartilhando o mesmo `CStringData` objeto.  
  
-   O buffer de caracteres real ( [dados](#data)) da cadeia de caracteres.  
  
    > [!NOTE]
    >  O buffer de caracteres real do objeto de cadeia de caracteres é alocado pelo Gerenciador de cadeia de caracteres e é anexado ao `CStringData` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpstr.h  
  
##  <a name="a-nameaddrefa--cstringdataaddref"></a><a name="addref"></a>CStringData::AddRef  
 Incrementa a contagem de referência do objeto de cadeia de caracteres.  
  
```
void AddRef() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Incrementa a contagem de referência do objeto de cadeia de caracteres.  
  
> [!NOTE]
>  Não chame esse método em uma cadeia de caracteres com uma contagem de referência negativo, pois uma contagem negativa indica que o buffer de cadeia de caracteres está bloqueado.  
  
##  <a name="a-namedataa--cstringdatadata"></a><a name="data"></a>CStringData::data  
 Retorna um ponteiro para o buffer de caracteres de um objeto de cadeia de caracteres.  
  
```
void* data() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o buffer de caracteres do objeto de cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para retornar o buffer de caracteres atual do objeto de cadeia de caracteres associado.  
  
> [!NOTE]
>  Esse buffer não está alocado pelo `CStringData` objeto mas pelo Gerenciador de cadeia de caracteres quando necessário. Quando alocados, o buffer é anexado ao objeto de dados de cadeia de caracteres.  
  
##  <a name="a-nameislockeda--cstringdataislocked"></a><a name="islocked"></a>CStringData::IsLocked  
 Determina se o buffer de caracteres está bloqueado.  
  
```
bool IsLocked() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o buffer for bloqueada; caso contrário **false**.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para determinar se o buffer de caracteres de um objeto de cadeia de caracteres está bloqueado no momento.  
  
##  <a name="a-nameisshareda--cstringdataisshared"></a><a name="isshared"></a>CStringData::IsShared  
 Determina se o buffer de caracteres é compartilhado.  
  
```
bool IsShared() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o buffer for compartilhada; caso contrário **false**.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para determinar se o buffer de caracteres de um objeto de dados de cadeia de caracteres estiver sendo compartilhado entre vários objetos de cadeia de caracteres.  
  
##  <a name="a-namelocka--cstringdatalock"></a><a name="lock"></a>CStringData::Lock  
 Bloqueia o buffer de caracteres do objeto de cadeia de caracteres associado.  
  
```
void Lock() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para bloquear o buffer de caracteres do objeto de dados de cadeia de caracteres. Bloqueando e desbloqueando é usado quando é necessário ter acesso direto ao buffer de caracteres pelo desenvolvedor. Um bom exemplo de bloqueio é demonstrado pelo [LockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [UnlockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) métodos de `CSimpleStringT`.  
  
> [!NOTE]
>  Um buffer de caracteres só pode ser bloqueado se o buffer não é compartilhado entre objetos de cadeia de caracteres mais alto.  
  
##  <a name="a-namenalloclengtha--cstringdatanalloclength"></a><a name="nalloclength"></a>CStringData::nAllocLength  
 Tamanho do buffer alocado de caractere.  
  
```
int nAllocLength;
```  
  
### <a name="remarks"></a>Comentários  
 Armazena o comprimento do buffer de dados alocados em `XCHAR`s (não incluindo a terminação nula).  
  
##  <a name="a-namendatalengtha--cstringdatandatalength"></a><a name="ndatalength"></a>CStringData::nDataLength  
 Tamanho atual do objeto de cadeia de caracteres.  
  
```
int nDataLength;
```  
  
### <a name="remarks"></a>Comentários  
 Armazena o tamanho dos dados atualmente em uso no `XCHAR`s (não incluindo a terminação nula).  
  
##  <a name="a-namenrefsa--cstringdatanrefs"></a><a name="nrefs"></a>CStringData::nRefs  
 Contagem de referência do objeto de dados de cadeia de caracteres.  
  
```
long nRefs;
```  
  
### <a name="remarks"></a>Comentários  
 Armazena a contagem de referência do objeto de dados de cadeia de caracteres. Essa contagem indica o número de objetos de cadeia de caracteres maior que estão associados ao objeto de dados de cadeia de caracteres. Um valor negativo indica que o objeto de dados de cadeia de caracteres está bloqueado no momento.  
  
##  <a name="a-namepstringmgra--cstringdatapstringmgr"></a><a name="pstringmgr"></a>CStringData::pStringMgr  
 O Gerenciador de memória do objeto de cadeia de caracteres associado.  
  
```
IAtlStringMgr* pStringMgr;
```  
  
### <a name="remarks"></a>Comentários  
 Armazena o Gerenciador de memória para o objeto de cadeia de caracteres associado. Para obter mais informações sobre gerenciadores de memória e cadeias de caracteres, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
##  <a name="a-namereleasea--cstringdatarelease"></a><a name="release"></a>CStringData::Release  
 Diminui a contagem de referência do objeto de dados de cadeia de caracteres.  
  
```
void Release() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para diminuir a contagem de referência, liberando o `CStringData` estrutura se a contagem de referência atinge zero. Isso geralmente ocorre quando um objeto de cadeia de caracteres é excluído e, portanto, não precisa fazer referência ao objeto de dados de cadeia de caracteres.  
  
 Por exemplo, o código a seguir chamaria `CStringData::Release` para o objeto de dados de cadeia de caracteres associado `str1`:  
  
 [!code-cpp[NVC_ATLMFC_Utilities&#104;](../../atl-mfc-shared/codesnippet/cpp/cstringdata-class_1.cpp)]  
  
##  <a name="a-nameunlocka--cstringdataunlock"></a><a name="unlock"></a>CStringData::Unlock  
 Desbloqueia o buffer de caracteres do objeto de cadeia de caracteres associado.  
  
```
void Unlock() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para desbloquear o buffer de caracteres do objeto de dados de cadeia de caracteres. Depois que um buffer é desbloqueado, ser compartilhada e pode ser referência contada.  
  
> [!NOTE]
>  Cada chamada para `Lock` ser correspondida por uma chamada correspondente para `Unlock`.  
  
 Bloqueando e desbloqueando é usado quando o desenvolvedor deve assegurar que os dados de cadeia de caracteres não seja compartilhada. Um bom exemplo de bloqueio é demonstrado pelo [LockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [UnlockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) métodos de `CSimpleStringT`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)



