---
title: Classe CMonikerFile | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMonikerFile
- AFXOLE/CMonikerFile
- AFXOLE/CMonikerFile::CMonikerFile
- AFXOLE/CMonikerFile::Close
- AFXOLE/CMonikerFile::Detach
- AFXOLE/CMonikerFile::GetMoniker
- AFXOLE/CMonikerFile::Open
- AFXOLE/CMonikerFile::CreateBindContext
dev_langs:
- C++
helpviewer_keywords:
- CMonikerFile class
- monikers, MFC
- IMoniker interface, binding
- IMoniker interface
ms.assetid: 87be5966-f4f7-4235-bce2-1fa39e9417de
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
ms.openlocfilehash: 4668672af1b33170ece1cb4d449ed5a20f6040e7
ms.lasthandoff: 02/25/2017

---
# <a name="cmonikerfile-class"></a>Classe CMonikerFile
Representa um fluxo de dados ( [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034)) chamado por um [IMoniker](http://msdn.microsoft.com/library/windows/desktop/ms679705).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMonikerFile : public COleStreamFile  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMonikerFile::CMonikerFile](#cmonikerfile)|Constrói um objeto `CMonikerFile`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMonikerFile::Close](#close)|Desanexa e libera o fluxo e libera o identificador de origem.|  
|[CMonikerFile::Detach](#detach)|Desanexa o `IMoniker` deste `CMonikerFile` objeto.|  
|[CMonikerFile::GetMoniker](#getmoniker)|Retorna o identificador de origem atual.|  
|[CMonikerFile::Open](#open)|Abre o arquivo especificado para obter um fluxo.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMonikerFile::CreateBindContext](#createbindcontext)|Obtém o contexto de ligação ou cria um contexto de associação padrão inicializado.|  
  
## <a name="remarks"></a>Comentários  
 Um identificador de origem contém informações muito parecido com um nome de caminho para um arquivo. Se você tiver um ponteiro para um objeto de moniker `IMoniker` interface, você pode obter acesso ao arquivo identificado sem a necessidade de quaisquer outras informações específicas sobre onde o arquivo está realmente localizado.  
  
 Derivado de `COleStreamFile`, `CMonikerFile` usa um identificador de origem ou uma representação de cadeia de caracteres pode fazer em um identificador de origem e associa o fluxo para que o identificador de origem é um nome. Em seguida, você pode ler e gravar no fluxo. A finalidade real `CMonikerFile` é fornecer acesso simples às `IStream`s nomeado pelo `IMoniker`s para que você não precisa associar a um fluxo, ainda têm `CFile` funcionalidade no fluxo.  
  
 `CMonikerFile`não pode ser usado para ligar a algo diferente de um fluxo. Se você deseja associar ao armazenamento ou a um objeto, você deve usar o `IMoniker` interface diretamente.  
  
 Para obter mais informações sobre fluxos e identificadores, consulte [COleStreamFile](../../mfc/reference/colestreamfile-class.md) no *referência da MFC* e [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034) e [IMoniker](http://msdn.microsoft.com/library/windows/desktop/ms679705) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [COleStreamFile](../../mfc/reference/colestreamfile-class.md)  
  
 `CMonikerFile`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="close"></a>CMonikerFile::Close  
 Chame essa função para desanexar e liberar o fluxo e liberar o identificador de origem.  
  
```  
virtual void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Pode ser chamado em fluxos não abertos ou fechados já.  
  
##  <a name="cmonikerfile"></a>CMonikerFile::CMonikerFile  
 Constrói um objeto `CMonikerFile`.  
  
```  
CMonikerFile();
```  
  
##  <a name="createbindcontext"></a>CMonikerFile::CreateBindContext  
 Chame essa função para criar um contexto de associação padrão inicializado.  
  
```  
IBindCtx* CreateBindContext(CFileException* pError);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pError`  
 Um ponteiro para uma exceção de arquivo. Se ocorrer um erro, ele definirá a causa.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o contexto de ligação [IBindCtx](http://msdn.microsoft.com/library/windows/desktop/ms693755) para associar com êxito, caso contrário **nulo**. Se a instância tiver sido aberta com um `IBindHost` interface, o contexto de ligação é obtido a `IBindHost`. Se não houver nenhum `IBindHost` interface ou a interface não retornar um contexto de ligação, um contexto de ligação é criado. Para obter uma descrição de [IBindHost](http://msdn.microsoft.com/library/ie/ms775076) de interface, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Um contexto de associação é um objeto que armazena informações sobre uma operação de vinculação do moniker específico. Você pode substituir essa função para fornecer um contexto de associação personalizado.  
  
##  <a name="detach"></a>CMonikerFile::Detach  
 Chame essa função para fechar o fluxo.  
  
```  
BOOL Detach(CFileException* pError = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pError`  
 Um ponteiro para uma exceção de arquivo. Se ocorrer um erro, ele definirá a causa.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="getmoniker"></a>CMonikerFile::GetMoniker  
 Chame essa função para recuperar um ponteiro para o moniker atual.  
  
```  
IMoniker* GetMoniker() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a interface do moniker atual ( [IMoniker](http://msdn.microsoft.com/library/windows/desktop/ms679705)).  
  
### <a name="remarks"></a>Comentários  
 Como `CMonikerFile` não é uma interface, o ponteiro retornado não incrementa a contagem de referência (por meio de [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379)), e o moniker é liberado quando o `CMonikerFile` o objeto é liberado. Se você quiser manter o moniker ou liberá-lo, você deve `AddRef` -lo.  
  
##  <a name="open"></a>CMonikerFile::Open  
 Chame essa função de membro para abrir um objeto de arquivo ou o identificador de origem.  
  
```  
virtual BOOL Open(
    LPCTSTR lpszURL,  
    CFileException* pError = NULL);

 
virtual BOOL Open(
    IMoniker* pMoniker,  
    CFileException* pError = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszURL`  
 Uma URL ou o nome do arquivo a ser aberto.  
  
 `pError`  
 Um ponteiro para uma exceção de arquivo. Se ocorrer um erro, ele definirá a causa.  
  
 `pMoniker`  
 Um ponteiro para a interface do moniker `IMoniker` a ser usado para obter um fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `lpszURL` parâmetro não pode ser usado em um Macintosh. Somente o `pMoniker` forma de **abrir** podem ser usados em um Macintosh.  
  
 Você pode usar uma URL ou um nome de arquivo para o `lpszURL` parâmetro. Por exemplo:  
  
 [!code-cpp[NVC_MFCWinInet n º&6;](../../mfc/codesnippet/cpp/cmonikerfile-class_1.cpp)]  
  
 – ou –  
  
 [!code-cpp[NVC_MFCWinInet&#7;](../../mfc/codesnippet/cpp/cmonikerfile-class_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe COleStreamFile](../../mfc/reference/colestreamfile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)

