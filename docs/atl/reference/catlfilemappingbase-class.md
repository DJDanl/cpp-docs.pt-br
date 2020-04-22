---
title: CAtlFileMappingBase Class
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
ms.openlocfilehash: 16eebfff4330a47888d1b60eaa993ee87d120f72
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748299"
---
# <a name="catlfilemappingbase-class"></a>CAtlFileMappingBase Class

Esta classe representa um arquivo mapeado pela memória.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAtlFileMappingBase
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFileMappingBase::CAtlFileMappingBase](#catlfilemappingbase)|O construtor.|
|[CAtlFileMappingBase::~CAtlFileMappingBase](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFileMappingBase::CopyFrom](#copyfrom)|Chame este método para copiar a partir de um objeto de mapeamento de arquivos.|
|[CAtlFileMappingBase::GetData](#getdata)|Chame este método para obter os dados de um objeto de mapeamento de arquivos.|
|[CAtlFileMappingBase::GetHandle](#gethandle)|Chame este método para devolver o cabo do arquivo.|
|[CAtlFileMappingBase::GetMappingSize](#getmappingsize)|Chame este método para obter o tamanho de mapeamento de um objeto de mapeamento de arquivos.|
|[CAtlFileMappingBase::MapFile](#mapfile)|Chame este método para criar um objeto de mapeamento de arquivos.|
|[CAtlFileMappingBase::MapSharedMem](#mapsharedmem)|Chame este método para criar um objeto de mapeamento de arquivos que permita acesso total a todos os processos.|
|[CAtlFileMappingBase::Mapeamento de abertura](#openmapping)|Chame este método para retornar uma alça ao objeto de mapeamento de arquivos.|
|[CAtlFileMappingBase::Desmapei](#unmap)|Chame este método para desmapear um objeto de mapeamento de arquivos.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlFileMappingBase::operador =](#operator_eq)|Define o objeto de mapeamento de arquivos atual como outro objeto de mapeamento de arquivos.|

## <a name="remarks"></a>Comentários

Mapeamento de arquivos é a associação do conteúdo de um arquivo com uma parte do espaço de endereço virtual de um processo. Essa classe fornece métodos para criar objetos de mapeamento de arquivos que permitem que os programas acessem e compartilhem dados facilmente.

Para obter mais informações, consulte [Mapeamento de arquivos](/windows/win32/Memory/file-mapping) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlfile.h

## <a name="catlfilemappingbasecatlfilemappingbase"></a><a name="catlfilemappingbase"></a>CAtlFileMappingBase::CAtlFileMappingBase

O construtor.

```
CAtlFileMappingBase(CAtlFileMappingBase& orig);
CAtlFileMappingBase() throw();
```

### <a name="parameters"></a>Parâmetros

*Orig*<br/>
O objeto original de mapeamento de arquivos a ser copiado para criar o novo objeto.

### <a name="remarks"></a>Comentários

Cria um novo objeto de mapeamento de arquivos, opcionalmente usando um objeto existente. Ainda é necessário chamar [CAtlFileMappingBase::MapFile](#mapfile) para abrir ou criar o objeto de mapeamento de arquivos para um determinado arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#71](../../atl/codesnippet/cpp/catlfilemappingbase-class_1.cpp)]

## <a name="catlfilemappingbasecatlfilemappingbase"></a><a name="dtor"></a>CAtlFileMappingBase::~CAtlFileMappingBase

O destruidor.

```
~CAtlFileMappingBase() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados pela classe e chama o método [CAtlFileMappingBase::Unmap.](#unmap)

## <a name="catlfilemappingbasecopyfrom"></a><a name="copyfrom"></a>CAtlFileMappingBase::CopyFrom

Chame este método para copiar a partir de um objeto de mapeamento de arquivos.

```
HRESULT CopyFrom(CAtlFileMappingBase& orig) throw();
```

### <a name="parameters"></a>Parâmetros

*Orig*<br/>
O objeto original de mapeamento de arquivos para copiar.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catlfilemappingbasegetdata"></a><a name="getdata"></a>CAtlFileMappingBase::GetData

Chame este método para obter os dados de um objeto de mapeamento de arquivos.

```cpp
void* GetData() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para os dados.

## <a name="catlfilemappingbasegethandle"></a><a name="gethandle"></a>CAtlFileMappingBase::GetHandle

Chame este método para retornar uma alça ao objeto de mapeamento de arquivos.

```
HANDLE GetHandle() throw ();
```

### <a name="return-value"></a>Valor retornado

Retorna uma alça para o objeto de mapeamento de arquivos.

## <a name="catlfilemappingbasegetmappingsize"></a><a name="getmappingsize"></a>CAtlFileMappingBase::GetMappingSize

Chame este método para obter o tamanho de mapeamento de um objeto de mapeamento de arquivos.

```
SIZE_T GetMappingSize() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o tamanho do mapeamento.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlFileMappingBase::CAtlFileMappingBase](#catlfilemappingbase).

## <a name="catlfilemappingbasemapfile"></a><a name="mapfile"></a>CAtlFileMappingBase::MapFile

Chame este método para abrir ou criar um objeto de mapeamento de arquivos para o arquivo especificado.

```
HRESULT MapFile(
    HANDLE hFile,
    SIZE_T nMappingSize = 0,
    ULONGLONG nOffset = 0,
    DWORD dwMappingProtection = PAGE_READONLY,
    DWORD dwViewDesiredAccess = FILE_MAP_READ) throw();
```

### <a name="parameters"></a>Parâmetros

*Hfile*<br/>
Manuseie o arquivo a partir do qual criar um objeto de mapeamento. *hFile* deve ser válido e não pode ser definido como INVALID_HANDLE_VALUE.

*nMappingSize*<br/>
O tamanho do mapeamento. Se 0, o tamanho máximo do objeto de mapeamento de arquivos é igual ao tamanho atual do arquivo identificado por *hFile.*

*nOffset*<br/>
O deslocamento do arquivo onde o mapeamento deve começar. O valor de deslocamento deve ser um múltiplo da granularidade de alocação de memória do sistema.

*dwMappingProtection*<br/>
A proteção desejada para a exibição do arquivo quando o arquivo é mapeado. Consulte *flProtect* in [CreateFileMapping](/windows/win32/api/winbase/nf-winbase-createfilemappinga) no Windows SDK.

*dwViewDesiredAccess*<br/>
Especifica o tipo de acesso à exibição do arquivo e, portanto, a proteção das páginas mapeadas pelo arquivo. Consulte *dwDesiredAccess* no [MapViewOfFileEx](/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Depois que um objeto de mapeamento de arquivos for criado, o tamanho do arquivo não deve exceder o tamanho do objeto de mapeamento de arquivos; se isso acontecer, nem todo o conteúdo do arquivo estará disponível para compartilhamento. Para obter mais detalhes, consulte [CreateFileMapping](/windows/win32/api/winbase/nf-winbase-createfilemappinga) e [MapViewOfFileEx](/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex) no Windows SDK.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlFileMappingBase::CAtlFileMappingBase](#catlfilemappingbase).

## <a name="catlfilemappingbasemapsharedmem"></a><a name="mapsharedmem"></a>CAtlFileMappingBase::MapSharedMem

Chame este método para criar um objeto de mapeamento de arquivos que permita acesso total a todos os processos.

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

*nMappingSize*<br/>
O tamanho do mapeamento. Se 0, o tamanho máximo do objeto de mapeamento de arquivos é igual ao tamanho atual do objeto de mapeamento de arquivos identificado por *szName*.

*Szname*<br/>
O nome do objeto de mapeamento.

*pbJáExistiu*<br/>
Aponta para um valor BOOL definido como TRUE se o objeto de mapeamento já existiu.

*LPSA*<br/>
O ponteiro `SECURITY_ATTRIBUTES` para uma estrutura que determina se a alça devolvida pode ser herdada por processos de crianças. Veja *lpAttributes* in [CreateFileMapping](/windows/win32/api/winbase/nf-winbase-createfilemappinga) no Windows SDK.

*dwMappingProtection*<br/>
A proteção desejada para a exibição do arquivo, quando o arquivo é mapeado. Consulte *flProtect* in `CreateFileMapping` no Windows SDK.

*dwViewDesiredAccess*<br/>
Especifica o tipo de acesso à exibição do arquivo e, portanto, a proteção das páginas mapeadas pelo arquivo. Consulte *dwDesiredAccess* no [MapViewOfFileEx](/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

`MapShareMem`permite que um objeto de mapeamento de arquivos existente, criado pelo [CreateFileMapping,](/windows/win32/api/winbase/nf-winbase-createfilemappinga)seja compartilhado entre os processos.

## <a name="catlfilemappingbaseopenmapping"></a><a name="openmapping"></a>CAtlFileMappingBase::Mapeamento de abertura

Chame este método para abrir um objeto de mapeamento de arquivos nomeado para o arquivo especificado.

```
HRESULT OpenMapping(
    LPCTSTR szName,
    SIZE_T nMappingSize,
    ULONGLONG nOffset = 0,
    DWORD dwViewDesiredAccess = FILE_MAP_ALL_ACCESS) throw();
```

### <a name="parameters"></a>Parâmetros

*Szname*<br/>
O nome do objeto de mapeamento. Se houver uma alça aberta para um objeto de mapeamento de arquivos por esse nome e o descritor de segurança no objeto de mapeamento não entrar em conflito com o parâmetro *dwViewDesiredAccess,* a operação aberta será bem sucedida.

*nMappingSize*<br/>
O tamanho do mapeamento. Se 0, o tamanho máximo do objeto de mapeamento de arquivos é igual ao tamanho atual do objeto de mapeamento de arquivos identificado por *szName*.

*nOffset*<br/>
O deslocamento do arquivo onde o mapeamento deve começar. O valor de deslocamento deve ser um múltiplo da granularidade de alocação de memória do sistema.

*dwViewDesiredAccess*<br/>
Especifica o tipo de acesso à exibição do arquivo e, portanto, a proteção das páginas mapeadas pelo arquivo. Consulte *dwDesiredAccess* no [MapViewOfFileEx](/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um erro de afirmação ocorrerá se os parâmetros de entrada forem inválidos.

## <a name="catlfilemappingbaseoperator-"></a><a name="operator_eq"></a>CAtlFileMappingBase::operador =

Define o objeto de mapeamento de arquivos atual como outro objeto de mapeamento de arquivos.

```
CAtlFileMappingBase& operator=(CAtlFileMappingBase& orig);
```

### <a name="parameters"></a>Parâmetros

*Orig*<br/>
O objeto de mapeamento de arquivos atual.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao objeto atual.

## <a name="catlfilemappingbaseunmap"></a><a name="unmap"></a>CAtlFileMappingBase::Desmapei

Chame este método para desmapear um objeto de mapeamento de arquivos.

```
HRESULT Unmap() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Consulte [UnmapViewOfFile](/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile) no Windows SDK para obter mais detalhes.

## <a name="see-also"></a>Confira também

[Classe catlfilemapping](../../atl/reference/catlfilemapping-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
