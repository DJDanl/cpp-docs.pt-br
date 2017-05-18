---
title: Classe CAtlFileMappingBase | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAtlFileMappingBase
- ATLFILE/ATL::CAtlFileMappingBase
- ATLFILE/ATL::CAtlFileMappingBase::CAtlFileMappingBase
- ATLFILE/ATL::CAtlFileMappingBase::CopyFrom
- ATLFILE/ATL::CAtlFileMappingBase::GetData
- ATLFILE/ATL::CAtlFileMappingBase::GetHandle
- ATLFILE/ATL::CAtlFileMappingBase::GetMappingSize
- ATLFILE/ATL::CAtlFileMappingBase::MapFile
- ATLFILE/ATL::CAtlFileMappingBase::MapSharedMem
- ATLFILE/ATL::CAtlFileMappingBase::OpenMapping
- ATLFILE/ATL::CAtlFileMappingBase::Unmap
dev_langs:
- C++
helpviewer_keywords:
- CAtlFileMappingBase class
ms.assetid: be555723-2790-4f57-a8fb-be4d68460775
caps.latest.revision: 20
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 439f123bc0addbbec2a26102d0197d0a1f14a8d5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="catlfilemappingbase-class"></a>Classe CAtlFileMappingBase
Essa classe representa um arquivo de memória mapeada.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CAtlFileMappingBase
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlFileMappingBase::CAtlFileMappingBase](#catlfilemappingbase)|O construtor.|  
|[CAtlFileMappingBase:: ~ CAtlFileMappingBase](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlFileMappingBase::CopyFrom](#copyfrom)|Chame esse método para copiar de um objeto de mapeamento de arquivo.|  
|[CAtlFileMappingBase::GetData](#getdata)|Chame esse método para obter os dados de um objeto de mapeamento de arquivo.|  
|[CAtlFileMappingBase::GetHandle](#gethandle)|Chame esse método para retornar o identificador de arquivo.|  
|[CAtlFileMappingBase::GetMappingSize](#getmappingsize)|Chame esse método para obter o tamanho do mapeamento de um objeto de mapeamento de arquivo.|  
|[CAtlFileMappingBase::MapFile](#mapfile)|Chame esse método para criar um objeto de mapeamento de arquivo.|  
|[CAtlFileMappingBase::MapSharedMem](#mapsharedmem)|Chame esse método para criar um objeto de mapeamento de arquivo que permite acesso total a todos os processos.|  
|[CAtlFileMappingBase::OpenMapping](#openmapping)|Chame esse método para retornar um identificador para o objeto de mapeamento de arquivo.|  
|[CAtlFileMappingBase::Unmap](#unmap)|Chame esse método para cancelar o mapeamento de um objeto de mapeamento de arquivo.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlFileMappingBase::operator =](#operator_eq)|Define o objeto de mapeamento de arquivo atual em outro objeto de mapeamento de arquivo.|  
  
## <a name="remarks"></a>Comentários  
 Mapeamento de arquivo é a associação de conteúdo do arquivo com uma parte do espaço de endereço virtual de um processo. Essa classe fornece métodos para criar objetos de mapeamento de arquivo que permitem que programas facilmente acessar e compartilhar dados.  
  
 Para obter mais informações, consulte [mapeamento de arquivos](http://msdn.microsoft.com/library/windows/desktop/aa366556) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlfile.h  
  
##  <a name="catlfilemappingbase"></a>CAtlFileMappingBase::CAtlFileMappingBase  
 O construtor.  
  
```
CAtlFileMappingBase(CAtlFileMappingBase& orig);  
CAtlFileMappingBase() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `orig`  
 O objeto de mapeamento de arquivo original para copiar para criar o novo objeto.  
  
### <a name="remarks"></a>Comentários  
 Cria um novo objeto de mapeamento de arquivos, opcionalmente usando um objeto existente. Ainda é necessário chamar [CAtlFileMappingBase::MapFile](#mapfile) abrir ou criar o objeto de mapeamento de arquivo para um arquivo específico.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities&#71;](../../atl/codesnippet/cpp/catlfilemappingbase-class_1.cpp)]  
  
##  <a name="dtor"></a>CAtlFileMappingBase:: ~ CAtlFileMappingBase  
 O destruidor.  
  
```
~CAtlFileMappingBase() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados por classe e chama o [CAtlFileMappingBase::Unmap](#unmap) método.  
  
##  <a name="copyfrom"></a>CAtlFileMappingBase::CopyFrom  
 Chame esse método para copiar de um objeto de mapeamento de arquivo.  
  
```
HRESULT CopyFrom(CAtlFileMappingBase& orig) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `orig`  
 O objeto de mapeamento de arquivo original para copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
##  <a name="getdata"></a>CAtlFileMappingBase::GetData  
 Chame esse método para obter os dados de um objeto de mapeamento de arquivo.  
  
```
void* GetData() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para os dados.  
  
##  <a name="gethandle"></a>CAtlFileMappingBase::GetHandle  
 Chame esse método para retornar um identificador para o objeto de mapeamento de arquivo.  
  
```
HANDLE GetHandle() throw ();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador para o objeto de mapeamento de arquivo.  
  
##  <a name="getmappingsize"></a>CAtlFileMappingBase::GetMappingSize  
 Chame esse método para obter o tamanho do mapeamento de um objeto de mapeamento de arquivo.  
  
```
SIZE_T GetMappingSize() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o tamanho do mapeamento.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CAtlFileMappingBase::CAtlFileMappingBase](#catlfilemappingbase).  
  
##  <a name="mapfile"></a>CAtlFileMappingBase::MapFile  
 Chame esse método para abrir ou criar um objeto de mapeamento de arquivo para o arquivo especificado.  
  
```
HRESULT MapFile(
    HANDLE hFile,
    SIZE_T nMappingSize = 0,
    ULONGLONG nOffset = 0,
    DWORD dwMappingProtection = PAGE_READONLY,
    DWORD dwViewDesiredAccess = FILE_MAP_READ) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hFile`  
 Identificador para o arquivo do qual criar um objeto de mapeamento. `hFile`deve ser válido e não pode ser definido como INVALID_HANDLE_VALUE.  
  
 `nMappingSize`  
 O tamanho do mapeamento. Se for 0, o tamanho máximo do objeto de mapeamento de arquivo é igual ao tamanho atual do arquivo identificado por *hFile.*  
  
 `nOffset`  
 O deslocamento de arquivo onde o mapeamento é para começar. O valor de deslocamento deve ser um múltiplo de granularidade de alocação de memória do sistema.  
  
 `dwMappingProtection`  
 A proteção desejada para o modo de exibição de arquivo quando o arquivo é mapeado. Consulte `flProtect` na [CreateFileMapping](http://msdn.microsoft.com/library/windows/desktop/aa366537) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwViewDesiredAccess`  
 Especifica o tipo de acesso para o modo de exibição de arquivo e, portanto, a proteção das páginas mapeado pelo arquivo. Consulte `dwDesiredAccess` na [MapViewOfFileEx](http://msdn.microsoft.com/library/windows/desktop/aa366763) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Depois que um objeto de mapeamento de arquivos tiver sido criado, o tamanho do arquivo não deve exceder o tamanho do objeto de mapeamento de arquivo; em caso afirmativo, não todo o conteúdo do arquivo estará disponível para o compartilhamento. Para obter mais detalhes, consulte [CreateFileMapping](http://msdn.microsoft.com/library/windows/desktop/aa366537) e [MapViewOfFileEx](http://msdn.microsoft.com/library/windows/desktop/aa366763) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CAtlFileMappingBase::CAtlFileMappingBase](#catlfilemappingbase).  
  
##  <a name="mapsharedmem"></a>CAtlFileMappingBase::MapSharedMem  
 Chame esse método para criar um objeto de mapeamento de arquivo que permite acesso total a todos os processos.  
  
```
HRESULT MapSharedMem(
    SIZE_T nMappingSize,
    LPCTSTR szName,
    BOOL* pbAlreadyExisted = NULL,
    LPSECURITY_ATTRIBUTES lpsa = NULL,
    DWORD dwMappingProtection = PAGE_READWRITE,
    DWORD dwViewDesiredAccess = FILE_MAP_ALL_ACCESS) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMappingSize`  
 O tamanho do mapeamento. Se for 0, o tamanho máximo do objeto de mapeamento de arquivo é igual ao tamanho atual do objeto de mapeamento do arquivo identificado por`szName.`  
  
 `szName`  
 O nome do objeto de mapeamento.  
  
 *pbAlreadyExisted*  
 Aponta para um valor booleano que é definida como TRUE se o objeto de mapeamento já existia.  
  
 `lpsa`  
 O ponteiro para uma **SECURITY_ATTRIBUTES** estrutura que determina se o identificador retornado pode ser herdado por processos filhos. Consulte *lpAttributes* na [CreateFileMapping](http://msdn.microsoft.com/library/windows/desktop/aa366537) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwMappingProtection`  
 A proteção desejada para o modo de exibição de arquivo, quando o arquivo é mapeado. Consulte `flProtect` na **CreateFileMapping** no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwViewDesiredAccess`  
 Especifica o tipo de acesso para o modo de exibição de arquivo e, portanto, a proteção das páginas mapeado pelo arquivo. Consulte `dwDesiredAccess` na [MapViewOfFileEx](http://msdn.microsoft.com/library/windows/desktop/aa366763) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 **MapShareMem** permite que um objeto de mapeamento de arquivo existente, criado por [CreateFileMapping](http://msdn.microsoft.com/library/windows/desktop/aa366537), para ser compartilhado entre processos.  
  
##  <a name="openmapping"></a>CAtlFileMappingBase::OpenMapping  
 Chame esse método para abrir um objeto de mapeamento de arquivo nomeado para o arquivo especificado.  
  
```
HRESULT OpenMapping(
    LPCTSTR szName,
    SIZE_T nMappingSize,
    ULONGLONG nOffset = 0,
    DWORD dwViewDesiredAccess = FILE_MAP_ALL_ACCESS) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `szName`  
 O nome do objeto de mapeamento. Se houver um identificador aberto para um objeto de mapeamento de arquivo com este nome e o descritor de segurança no objeto de mapeamento não entra em conflito com o `dwViewDesiredAccess` bem-sucedida do parâmetro, a operação de abertura.  
  
 `nMappingSize`  
 O tamanho do mapeamento. Se for 0, o tamanho máximo do objeto de mapeamento de arquivo é igual ao tamanho atual do objeto de mapeamento do arquivo identificado por`szName.`  
  
 `nOffset`  
 O deslocamento de arquivo onde o mapeamento é para começar. O valor de deslocamento deve ser um múltiplo de granularidade de alocação de memória do sistema.  
  
 `dwViewDesiredAccess`  
 Especifica o tipo de acesso para o modo de exibição de arquivo e, portanto, a proteção das páginas mapeado pelo arquivo. Consulte `dwDesiredAccess` na [MapViewOfFileEx](http://msdn.microsoft.com/library/windows/desktop/aa366763) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Compilações de depuração, um erro de asserção ocorrerá se os parâmetros de entrada são inválidos.  
  
##  <a name="operator_eq"></a>CAtlFileMappingBase::operator =  
 Define o objeto de mapeamento de arquivo atual em outro objeto de mapeamento de arquivo.  
  
```
CAtlFileMappingBase& operator=(CAtlFileMappingBase& orig);
```  
  
### <a name="parameters"></a>Parâmetros  
 `orig`  
 O objeto de mapeamento de arquivo atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência ao objeto atual.  
  
##  <a name="unmap"></a>CAtlFileMappingBase::Unmap  
 Chame esse método para cancelar o mapeamento de um objeto de mapeamento de arquivo.  
  
```
HRESULT Unmap() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` no sucesso ou erro `HRESULT` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Consulte [UnmapViewOfFile](http://msdn.microsoft.com/library/windows/desktop/aa366882) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais detalhes.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlFileMapping](../../atl/reference/catlfilemapping-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

