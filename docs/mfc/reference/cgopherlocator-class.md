---
title: Classe CGopherLocator
ms.date: 11/04/2016
f1_keywords:
- CGopherLocator
- AFXINET/CGopherLocator
- AFXINET/CGopherLocator::CGopherLocator
- AFXINET/CGopherLocator::GetLocatorType
helpviewer_keywords:
- CGopherLocator [MFC], CGopherLocator
- CGopherLocator [MFC], GetLocatorType
ms.assetid: 6fcc015f-5ae6-4959-b936-858634c71019
ms.openlocfilehash: d23ef3dad68c62e74ec64454953ca372b8c31114
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373673"
---
# <a name="cgopherlocator-class"></a>Classe CGopherLocator

Obtém um "localizador" gopher de um servidor gopher, determina o tipo do localizador e disponibiliza o localizador para [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md).

> [!NOTE]
> As `CGopherConnection`classes `CGopherFile` `CGopherFileFind`e `CGopherLocator` seus membros foram preteridos porque não trabalham na plataforma Windows XP, mas continuarão a trabalhar em plataformas anteriores.

## <a name="syntax"></a>Sintaxe

```
class CGopherLocator : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CGopherLocator::CGopherLocator](#cgopherlocator)|Constrói um objeto `CGopherLocator`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CGopherLocator::GetLocatorType](#getlocatortype)|Analisa um localizador de gopher e determina seus atributos.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CGopherLocator::operador LPCTSTR](#operator_lpctstr)|Acessa diretamente caracteres armazenados em um `CGopherLocator` objeto como uma seqüência de caracteres estilo C.|

## <a name="remarks"></a>Comentários

Um aplicativo deve obter o localizador de um servidor gopher antes que ele possa recuperar informações desse servidor. Uma vez que tenha o localizador, deve tratar o localizador como um token opaco.

Cada localizador gopher tem atributos que determinam o tipo de arquivo ou servidor encontrado. Consulte [GetLocatorType](#getlocatortype) para obter uma lista de tipos de localizadores gopher.

Um aplicativo normalmente usa o localizador para chamadas para [CGopherFileFind::FindFile](../../mfc/reference/cgopherfilefind-class.md#findfile) para recuperar uma informação específica.

Para saber mais `CGopherLocator` sobre como funciona as outras aulas de Internet do MFC, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CGopherLocator`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cgopherlocatorcgopherlocator"></a><a name="cgopherlocator"></a>CGopherLocator::CGopherLocator

Esta função de membro `CGopherLocator` é chamada para criar um objeto.

```
CGopherLocator(const CGopherLocator& ref);
```

### <a name="parameters"></a>Parâmetros

*ref*<br/>
Uma referência a `CGopherLocator` um objeto constante.

### <a name="remarks"></a>Comentários

Você nunca `CGopherLocator` cria um objeto diretamente. Em vez disso, chame [CGopherConnection::CreateLocator](../../mfc/reference/cgopherconnection-class.md#createlocator) para `CGopherLocator` criar e retornar um ponteiro para o objeto.

## <a name="cgopherlocatorgetlocatortype"></a><a name="getlocatortype"></a>CGopherLocator::GetLocatorType

Ligue para esta função de membro para obter o tipo de localizador.

```
BOOL GetLocatorType(DWORD& dwRef) const;
```

### <a name="parameters"></a>Parâmetros

*dwRef*<br/>
Uma referência a um DWORD que receberá o tipo de localizador. Consulte **Observações** para uma tabela de tipos de localizadores.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Os tipos possíveis são os seguintes:

|Valor|Significado|
|-----------|-------------|
|GOPHER_TYPE_TEXT_FILE|Um arquivo de texto ASCII.|
|GOPHER_TYPE_DIRECTORY|Um diretório de itens adicionais do Gopher.|
|GOPHER_TYPE_CSO|Um servidor de lista telefônica CSO.|
|GOPHER_TYPE_ERROR|Indica uma condição de erro.|
|GOPHER_TYPE_MAC_BINHEX|Um arquivo Macintosh no formato BINHEX.|
|GOPHER_TYPE_DOS_ARCHIVE|Um arquivo DOS.|
|GOPHER_TYPE_UNIX_UUENCODED|Um arquivo UUENCODED.|
|GOPHER_TYPE_INDEX_SERVER|Um servidor de índice.|
|GOPHER_TYPE_TELNET|Um servidor Telnet.|
|GOPHER_TYPE_BINARY|Um arquivo binário.|
|GOPHER_TYPE_REDUNDANT|Um servidor duplicado. As informações contidas são uma duplicata do servidor principal. O servidor principal é a última entrada de diretório que não tinha um tipo de GOPHER_TYPE_REDUNDANT.|
|GOPHER_TYPE_TN3270|Um servidor TN3270.|
|GOPHER_TYPE_GIF|Um arquivo gráfico GIF.|
|GOPHER_TYPE_IMAGE|Um arquivo de imagem.|
|GOPHER_TYPE_BITMAP|Um arquivo bitmap.|
|GOPHER_TYPE_MOVIE|Um arquivo de filme.|
|GOPHER_TYPE_SOUND|Um arquivo de som.|
|GOPHER_TYPE_HTML|Um documento HTML.|
|GOPHER_TYPE_PDF|Um arquivo PDF.|
|GOPHER_TYPE_CALENDAR|Um arquivo de calendário.|
|GOPHER_TYPE_INLINE|Um arquivo inline.|
|GOPHER_TYPE_UNKNOWN|O tipo de item é desconhecido.|
|GOPHER_TYPE_ASK|Um item Ask+.|
|GOPHER_TYPE_GOPHER_PLUS|Um item Gopher+.|

## <a name="cgopherlocatoroperator-lpctstr"></a><a name="operator_lpctstr"></a>CGopherLocator::operador LPCTSTR

Este operador de fundição útil fornece um método eficiente para `CGopherLocator` acessar a seqüência C com término nulo contida em um objeto.

```
operator LPCTSTR () const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro de caracteres para os dados da seqüência.

### <a name="remarks"></a>Comentários

Nenhum caractere é copiado; apenas um ponteiro é devolvido.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)
