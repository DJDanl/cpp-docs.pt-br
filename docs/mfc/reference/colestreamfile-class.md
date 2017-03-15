---
title: Classe COleStreamFile | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleStreamFile
dev_langs:
- C++
helpviewer_keywords:
- data streams [C++]
- streams [C++], OLE
- data streams [C++], OLE
- structured storage in OLE
- OLE structured storage [C++]
- OLE [C++], streams of data
- COleStreamFile class
ms.assetid: e4f93698-e17c-4a18-a7c0-4b4df8eb4d93
caps.latest.revision: 22
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 0840d365f4179da0ad680256688eaf9484cb3cd8
ms.lasthandoff: 02/25/2017

---
# <a name="colestreamfile-class"></a>Classe COleStreamFile
Representa um fluxo de dados ( `IStream`) em um arquivo composto como parte do armazenamento estruturado OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleStreamFile : public CFile  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleStreamFile::COleStreamFile](#colestreamfile)|Constrói um objeto `COleStreamFile`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleStreamFile::Attach](#attach)|Associa um fluxo com o objeto.|  
|[COleStreamFile::CreateMemoryStream](#creatememorystream)|Cria um fluxo de memória global e o associa ao objeto.|  
|[COleStreamFile::CreateStream](#createstream)|Cria um fluxo e associa o objeto.|  
|[COleStreamFile::Detach](#detach)|Desassocia o fluxo do objeto.|  
|[COleStreamFile::GetStream](#getstream)|Retorna o fluxo atual.|  
|[COleStreamFile::OpenStream](#openstream)|Abre um fluxo e associa o objeto com segurança.|  
  
## <a name="remarks"></a>Comentários  
 Um `IStorage` objeto deve existir antes do fluxo pode ser aberto ou criado a menos que ele seja um fluxo de memória.  
  
 `COleStreamFile`os objetos são manipulados exatamente como [CFile](../../mfc/reference/cfile-class.md) objetos.  
  
 Para obter mais informações sobre a manipulação de fluxos e armazenamentos, consulte o artigo [contêineres: arquivos compostos](../../mfc/containers-compound-files.md)...  
  
 Para obter mais informações, consulte [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034) e [IStorage](http://msdn.microsoft.com/library/windows/desktop/aa380015) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 `COleStreamFile`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="a-nameattacha--colestreamfileattach"></a><a name="attach"></a>COleStreamFile::Attach  
 Associa o fluxo OLE fornecido com o `COleStreamFile` objeto.  
  
```  
void Attach(LPSTREAM lpStream);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpStream`  
 Aponta para o fluxo OLE ( `IStream`) a ser associado com o objeto. Não pode ser **nulo**.  
  
### <a name="remarks"></a>Comentários  
 O objeto não já deve estar associado um fluxo OLE.  
  
 Para obter mais informações, consulte [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namecolestreamfilea--colestreamfilecolestreamfile"></a><a name="colestreamfile"></a>COleStreamFile::COleStreamFile  
 Cria um objeto `COleStreamFile`.  
  
```  
COleStreamFile(LPSTREAM lpStream = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpStream`  
 Ponteiro para o fluxo OLE a ser associado ao objeto.  
  
### <a name="remarks"></a>Comentários  
 Se `lpStream` é **nulo**, o objeto não está associado um fluxo OLE, caso contrário, o objeto é associado com o fluxo OLE fornecido.  
  
 Para obter mais informações, consulte [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namecreatememorystreama--colestreamfilecreatememorystream"></a><a name="creatememorystream"></a>COleStreamFile::CreateMemoryStream  
 Com segurança, cria um novo fluxo sem memória global e compartilhada em que uma falha é uma condição normal e esperada.  
  
```  
BOOL CreateMemoryStream(CFileException* pError = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pError`  
 Aponta para um [CFileException](../../mfc/reference/cfileexception-class.md) objeto ou **nulo** que indica o status de conclusão da operação criar. Forneça esse parâmetro se desejar monitorar possíveis exceções geradas pela tentativa de criar o fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o fluxo é criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A memória é alocada pelo subsistema de OLE.  
  
 Para obter mais informações, consulte [CreateStreamOnHGlobal](http://msdn.microsoft.com/library/windows/desktop/aa378980) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namecreatestreama--colestreamfilecreatestream"></a><a name="createstream"></a>COleStreamFile::CreateStream  
 Com segurança, cria um novo fluxo no objeto de armazenamento fornecido em que uma falha é uma condição normal e esperada.  
  
```  
BOOL CreateStream(
    LPSTORAGE lpStorage,  
    LPCTSTR lpszStreamName,  
    DWORD nOpenFlags = modeReadWrite|shareExclusive|modeCreate,  
    CFileException* pError = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpStorage`  
 Aponta para o objeto de armazenamento OLE que contém o fluxo a ser criado. Não pode ser **nulo**.  
  
 `lpszStreamName`  
 Nome do fluxo a ser criado. Não pode ser **nulo**.  
  
 `nOpenFlags`  
 Modo de acesso para usar ao abrir o fluxo. Leitura/gravação exclusivo e criar modos são usados por padrão. Para obter uma lista completa dos modos disponíveis, consulte [CFile::CFile](../../mfc/reference/cfile-class.md#cfile).  
  
 `pError`  
 Aponta para um [CFileException](../../mfc/reference/cfileexception-class.md) objeto ou **nulo**. Forneça esse parâmetro se desejar monitorar possíveis exceções geradas pela tentativa de criar o fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o fluxo é criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Uma exceção de arquivo será gerada se o open falha e `pError` não é **nulo**.  
  
 Para obter mais informações, consulte [IStorage::CreateStream](http://msdn.microsoft.com/library/windows/desktop/aa380020) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namedetacha--colestreamfiledetach"></a><a name="detach"></a>COleStreamFile::Detach  
 Desassocia o fluxo do objeto sem fechar o fluxo.  
  
```  
LPSTREAM Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o fluxo ( `IStream`) que foi associado ao objeto.  
  
### <a name="remarks"></a>Comentários  
 O fluxo deve ser fechado de alguma outra forma antes que o programa é encerrado.  
  
 Para obter mais informações, consulte [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetstreama--colestreamfilegetstream"></a><a name="getstream"></a>COleStreamFile::GetStream  
 Chame essa função para retornar um ponteiro para o fluxo atual.  
  
```  
IStream* GetStream() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a interface do fluxo atual ( [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034)).  
  
##  <a name="a-nameopenstreama--colestreamfileopenstream"></a><a name="openstream"></a>COleStreamFile::OpenStream  
 Abre um fluxo existente.  
  
```  
BOOL OpenStream(
    LPSTORAGE lpStorage,  
    LPCTSTR lpszStreamName,  
    DWORD nOpenFlags = modeReadWrite|shareExclusive,  
    CFileException* pError = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpStorage`  
 Aponta para o objeto de armazenamento OLE que contém o fluxo a ser aberto. Não pode ser **nulo**.  
  
 `lpszStreamName`  
 Nome do fluxo a ser aberto. Não pode ser **nulo**.  
  
 `nOpenFlags`  
 Modo de acesso para usar ao abrir o fluxo. Exclusivo e leitura/gravação são utilizados por padrão. Para obter uma lista completa dos modos disponíveis, consulte [CFile::CFile](../../mfc/reference/cfile-class.md#cfile).  
  
 `pError`  
 Aponta para um [CFileException](../../mfc/reference/cfileexception-class.md) objeto ou **nulo**. Forneça esse parâmetro se desejar monitorar possíveis exceções geradas ao tentar abrir o fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o fluxo é aberto com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Uma exceção de arquivo será gerada se o open falha e `pError` não é **nulo**.  
  
 Para obter mais informações, consulte [IStorage::OpenStream](http://msdn.microsoft.com/library/windows/desktop/aa380025) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFile](../../mfc/reference/cfile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




