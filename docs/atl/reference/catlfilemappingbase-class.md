---
title: Classe CAtlFileMappingBase
ms.date: 11/04/2016
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
helpviewer_keywords:
- CAtlFileMappingBase class
ms.assetid: be555723-2790-4f57-a8fb-be4d68460775
ms.openlocfilehash: 75177c195e83a4ab3ad2a6bd4d608d07f8c2234f
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168079"
---
# <a name="catlfilemappingbase-class"></a>Classe CAtlFileMappingBase

Essa classe representa um arquivo mapeado por memória.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
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
|[CAtlFileMappingBase:: GetData](#getdata)|Chame esse método para obter os dados de um objeto de mapeamento de arquivo.|
|[CAtlFileMappingBase:: GetHandle](#gethandle)|Chame esse método para retornar o identificador de arquivo.|
|[CAtlFileMappingBase::GetMappingSize](#getmappingsize)|Chame esse método para obter o tamanho do mapeamento de um objeto de mapeamento de arquivo.|
|[CAtlFileMappingBase:: mapa](#mapfile)|Chame esse método para criar um objeto de mapeamento de arquivo.|
|[CAtlFileMappingBase::MapSharedMem](#mapsharedmem)|Chame esse método para criar um objeto de mapeamento de arquivo que permita acesso completo a todos os processos.|
|[CAtlFileMappingBase::OpenMapping](#openmapping)|Chame esse método para retornar um identificador para o objeto de mapeamento de arquivo.|
|[CAtlFileMappingBase:: mapeamento](#unmap)|Chame esse método para desmapear um objeto de mapeamento de arquivo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFileMappingBase:: Operator =](#operator_eq)|Define o objeto de mapeamento de arquivo atual para outro objeto de mapeamento de arquivo.|

## <a name="remarks"></a>Comentários

O mapeamento de arquivo é a associação do conteúdo de um arquivo com uma parte do espaço de endereço virtual de um processo. Essa classe fornece métodos para criar objetos de mapeamento de arquivos que permitem que os programas acessem e compartilhem dados facilmente.

Para obter mais informações, consulte [mapeamento de arquivo](/windows/win32/Memory/file-mapping) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlfile. h

## <a name="catlfilemappingbasecatlfilemappingbase"></a><a name="catlfilemappingbase"></a>CAtlFileMappingBase::CAtlFileMappingBase

O construtor.

```cpp
CAtlFileMappingBase(CAtlFileMappingBase& orig);
CAtlFileMappingBase() throw();
```

### <a name="parameters"></a>Parâmetros

*orig*<br/>
O objeto de mapeamento de arquivo original a ser copiado para criar o novo objeto.

### <a name="remarks"></a>Comentários

Cria um novo objeto de mapeamento de arquivo, opcionalmente usando um objeto existente. Ainda é necessário chamar [CAtlFileMappingBase:: mapa](#mapfile) para abrir ou criar o objeto de mapeamento de arquivo para um arquivo específico.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#71](../../atl/codesnippet/cpp/catlfilemappingbase-class_1.cpp)]

## <a name="catlfilemappingbasecatlfilemappingbase"></a><a name="dtor"></a>CAtlFileMappingBase:: ~ CAtlFileMappingBase

O destruidor.

```cpp
~CAtlFileMappingBase() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados pela classe e chama o método [CAtlFileMappingBase:: remapeamento](#unmap) .

## <a name="catlfilemappingbasecopyfrom"></a><a name="copyfrom"></a>CAtlFileMappingBase::CopyFrom

Chame esse método para copiar de um objeto de mapeamento de arquivo.

```cpp
HRESULT CopyFrom(CAtlFileMappingBase& orig) throw();
```

### <a name="parameters"></a>Parâmetros

*orig*<br/>
O objeto de mapeamento de arquivo original do qual copiar.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="catlfilemappingbasegetdata"></a><a name="getdata"></a>CAtlFileMappingBase:: GetData

Chame esse método para obter os dados de um objeto de mapeamento de arquivo.

```cpp
void* GetData() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para os dados.

## <a name="catlfilemappingbasegethandle"></a><a name="gethandle"></a>CAtlFileMappingBase:: GetHandle

Chame esse método para retornar um identificador para o objeto de mapeamento de arquivo.

```cpp
HANDLE GetHandle() throw ();
```

### <a name="return-value"></a>Valor retornado

Retorna um identificador para o objeto de mapeamento de arquivo.

## <a name="catlfilemappingbasegetmappingsize"></a><a name="getmappingsize"></a>CAtlFileMappingBase::GetMappingSize

Chame esse método para obter o tamanho do mapeamento de um objeto de mapeamento de arquivo.

```cpp
SIZE_T GetMappingSize() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o tamanho do mapeamento.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlFileMappingBase:: CAtlFileMappingBase](#catlfilemappingbase).

## <a name="catlfilemappingbasemapfile"></a><a name="mapfile"></a>CAtlFileMappingBase:: mapa

Chame esse método para abrir ou criar um objeto de mapeamento de arquivo para o arquivo especificado.

```cpp
HRESULT MapFile(
    HANDLE hFile,
    SIZE_T nMappingSize = 0,
    ULONGLONG nOffset = 0,
    DWORD dwMappingProtection = PAGE_READONLY,
    DWORD dwViewDesiredAccess = FILE_MAP_READ) throw();
```

### <a name="parameters"></a>Parâmetros

*hFile*<br/>
Identificador para o arquivo do qual criar um objeto de mapeamento. *hFile* deve ser válido e não pode ser definido como INVALID_HANDLE_VALUE.

*nMappingSize*<br/>
O tamanho do mapeamento. Se 0, o tamanho máximo do objeto de mapeamento de arquivo é igual ao tamanho atual do arquivo identificado por *hFile.*

*nOffset*<br/>
O deslocamento do arquivo onde o mapeamento deve começar. O valor de deslocamento deve ser um múltiplo da granularidade de alocação de memória do sistema.

*dwMappingProtection*<br/>
A proteção desejada para a exibição de arquivo quando o arquivo é mapeado. Consulte *flProtect* em [CreateFileMapping](/windows/win32/api/winbase/nf-winbase-createfilemappinga) na SDK do Windows.

*dwViewDesiredAccess*<br/>
Especifica o tipo de acesso à exibição de arquivo e, portanto, a proteção das páginas mapeadas pelo arquivo. Consulte *dwDesiredAccess* em [MapViewOfFileEx](/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex) na SDK do Windows.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Após a criação de um objeto de mapeamento de arquivo, o tamanho do arquivo não deve exceder o tamanho do objeto de mapeamento de arquivo; Se isso ocorrer, nem todo o conteúdo do arquivo estará disponível para compartilhamento. Para obter mais detalhes, consulte [CreateFileMapping](/windows/win32/api/winbase/nf-winbase-createfilemappinga) e [MapViewOfFileEx](/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex) no SDK do Windows.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlFileMappingBase:: CAtlFileMappingBase](#catlfilemappingbase).

## <a name="catlfilemappingbasemapsharedmem"></a><a name="mapsharedmem"></a>CAtlFileMappingBase::MapSharedMem

Chame esse método para criar um objeto de mapeamento de arquivo que permita acesso completo a todos os processos.

```cpp
HRESULT MapSharedMem(
    SIZE_T nMappingSize,
    LPCTSTR szName,
    BOOL* pbAlreadyExisted = NULL,
    LPSECURITY_ATTRIBUTES lpsa = NULL,
    DWORD dwMappingProtection = PAGE_READWRITE,
    DWORD dwViewDesiredAccess = FILE_MAP_ALL_ACCESS) throw();
```

### <a name="parameters"></a>Parâmetros

*nMappingSize*<br/>
O tamanho do mapeamento. Se 0, o tamanho máximo do objeto de mapeamento de arquivo é igual ao tamanho atual do objeto de mapeamento de arquivo identificado por *szName*.

*szName*<br/>
O nome do objeto de mapeamento.

*pbAlreadyExisted*<br/>
Aponta para um valor BOOL definido como TRUE se o objeto de mapeamento já existia.

*lpsa*<br/>
O ponteiro para uma `SECURITY_ATTRIBUTES` estrutura que determina se o identificador retornado pode ser herdado por processos filho. Consulte *lpAttributes* em [CreateFileMapping](/windows/win32/api/winbase/nf-winbase-createfilemappinga) na SDK do Windows.

*dwMappingProtection*<br/>
A proteção desejada para a exibição do arquivo, quando o arquivo é mapeado. Consulte *flProtect* no `CreateFileMapping` SDK do Windows.

*dwViewDesiredAccess*<br/>
Especifica o tipo de acesso à exibição de arquivo e, portanto, a proteção das páginas mapeadas pelo arquivo. Consulte *dwDesiredAccess* em [MapViewOfFileEx](/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex) na SDK do Windows.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

`MapShareMem`permite que um objeto de mapeamento de arquivo existente, criado por [CreateFileMapping](/windows/win32/api/winbase/nf-winbase-createfilemappinga), seja compartilhado entre processos.

## <a name="catlfilemappingbaseopenmapping"></a><a name="openmapping"></a>CAtlFileMappingBase::OpenMapping

Chame esse método para abrir um objeto de mapeamento de arquivo nomeado para o arquivo especificado.

```cpp
HRESULT OpenMapping(
    LPCTSTR szName,
    SIZE_T nMappingSize,
    ULONGLONG nOffset = 0,
    DWORD dwViewDesiredAccess = FILE_MAP_ALL_ACCESS) throw();
```

### <a name="parameters"></a>Parâmetros

*szName*<br/>
O nome do objeto de mapeamento. Se houver um identificador aberto para um objeto de mapeamento de arquivo por esse nome e o descritor de segurança no objeto de mapeamento não entrar em conflito com o parâmetro *dwViewDesiredAccess* , a operação abrir terá sucesso.

*nMappingSize*<br/>
O tamanho do mapeamento. Se 0, o tamanho máximo do objeto de mapeamento de arquivo é igual ao tamanho atual do objeto de mapeamento de arquivo identificado por *szName*.

*nOffset*<br/>
O deslocamento do arquivo onde o mapeamento deve começar. O valor de deslocamento deve ser um múltiplo da granularidade de alocação de memória do sistema.

*dwViewDesiredAccess*<br/>
Especifica o tipo de acesso à exibição de arquivo e, portanto, a proteção das páginas mapeadas pelo arquivo. Consulte *dwDesiredAccess* em [MapViewOfFileEx](/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex) na SDK do Windows.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá um erro de asserção se os parâmetros de entrada forem inválidos.

## <a name="catlfilemappingbaseoperator-"></a><a name="operator_eq"></a>CAtlFileMappingBase:: Operator =

Define o objeto de mapeamento de arquivo atual para outro objeto de mapeamento de arquivo.

```cpp
CAtlFileMappingBase& operator=(CAtlFileMappingBase& orig);
```

### <a name="parameters"></a>Parâmetros

*orig*<br/>
O objeto de mapeamento de arquivo atual.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao objeto atual.

## <a name="catlfilemappingbaseunmap"></a><a name="unmap"></a>CAtlFileMappingBase:: mapeamento

Chame esse método para desmapear um objeto de mapeamento de arquivo.

```cpp
HRESULT Unmap() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Consulte [UnmapViewOfFile](/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile) no SDK do Windows para obter mais detalhes.

## <a name="see-also"></a>Confira também

[Classe CAtlFileMapping](../../atl/reference/catlfilemapping-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
