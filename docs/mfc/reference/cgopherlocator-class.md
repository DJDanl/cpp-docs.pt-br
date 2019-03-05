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
ms.openlocfilehash: 79adbf126438c7d9f2884987c53b573991f92cf1
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57291373"
---
# <a name="cgopherlocator-class"></a>Classe CGopherLocator

Obtém um gopher "localizador" de um servidor gopher, determina o tipo de localizador e torna o localizador disponível para [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md).

> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind`, `CGopherLocator` e seus membros foram preteridos porque eles não funcionam na plataforma Windows XP, mas eles continuarão a funcionar em plataformas anteriores.

## <a name="syntax"></a>Sintaxe

```
class CGopherLocator : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CGopherLocator::CGopherLocator](#cgopherlocator)|Constrói um objeto `CGopherLocator`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CGopherLocator::GetLocatorType](#getlocatortype)|Analisa um localizador de gopher e determina seus atributos.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CGopherLocator::operator LPCTSTR](#operator_lpctstr)|Acessa diretamente caracteres armazenados em uma `CGopherLocator` objeto como uma cadeia de caracteres de estilo C.|

## <a name="remarks"></a>Comentários

Um aplicativo deve obter o localizador do servidor gopher antes que ele pode recuperar informações do servidor. Uma vez que ele tem o localizador, ele deve tratar o localizador como um token opaco.

Cada localizador gopher tem atributos que determinam o tipo de arquivo ou servidor encontrado. Ver [GetLocatorType](#getlocatortype) para obter uma lista dos tipos de localizadores gopher.

Um aplicativo normalmente usa o localizador para chamadas para [CGopherFileFind::FindFile](../../mfc/reference/cgopherfilefind-class.md#findfile) para recuperar uma parte específica de informações.

Para saber mais sobre como `CGopherLocator` funciona com as outras classes de Internet do MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CGopherLocator`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

##  <a name="cgopherlocator"></a>  CGopherLocator::CGopherLocator

Essa função membro é chamada para criar um `CGopherLocator` objeto.

```
CGopherLocator(const CGopherLocator& ref);
```

### <a name="parameters"></a>Parâmetros

*ref*<br/>
Uma referência a uma constante `CGopherLocator` objeto.

### <a name="remarks"></a>Comentários

Você nunca criará um `CGopherLocator` diretamente do objeto. Em vez disso, chame [CGopherConnection::CreateLocator](../../mfc/reference/cgopherconnection-class.md#createlocator) para criar e retornar um ponteiro para o `CGopherLocator` objeto.

##  <a name="getlocatortype"></a>  CGopherLocator::GetLocatorType

Chame essa função de membro para obter o tipo de localizador.

```
BOOL GetLocatorType(DWORD& dwRef) const;
```

### <a name="parameters"></a>Parâmetros

*dwRef*<br/>
Uma referência a um DWORD que receberá o tipo de localizador. Ver **comentários** para uma tabela de tipos de localizador.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Os possíveis tipos são da seguinte maneira:

|Valor|Significado|
|-----------|-------------|
|GOPHER_TYPE_TEXT_FILE|Um arquivo de texto ASCII.|
|GOPHER_TYPE_DIRECTORY|Um diretório de itens adicionais de Gopher.|
|GOPHER_TYPE_CSO|Um servidor de catálogo telefônico CSO.|
|GOPHER_TYPE_ERROR|Indica uma condição de erro.|
|GOPHER_TYPE_MAC_BINHEX|Um arquivo do Macintosh em formato BINHEX.|
|GOPHER_TYPE_DOS_ARCHIVE|Um arquivo morto DOS.|
|GOPHER_TYPE_UNIX_UUENCODED|Um arquivo com codificação UU.|
|GOPHER_TYPE_INDEX_SERVER|Um servidor de índice.|
|GOPHER_TYPE_TELNET|A Telnet Server.|
|GOPHER_TYPE_BINARY|Um arquivo binário.|
|GOPHER_TYPE_REDUNDANT|Um servidor duplicado. As informações contidas em são uma duplicata do servidor primário. O servidor primário é a última entrada de diretório que não tem um tipo GOPHER_TYPE_REDUNDANT.|
|GOPHER_TYPE_TN3270|Um servidor TN3270.|
|GOPHER_TYPE_GIF|Um arquivo de gráfico GIF.|
|GOPHER_TYPE_IMAGE|Um arquivo de imagem.|
|GOPHER_TYPE_BITMAP|Um arquivo de bitmap.|
|GOPHER_TYPE_MOVIE|Um arquivo de filme.|
|GOPHER_TYPE_SOUND|Um arquivo de som.|
|GOPHER_TYPE_HTML|Um documento HTML.|
|GOPHER_TYPE_PDF|Um arquivo PDF.|
|GOPHER_TYPE_CALENDAR|Um arquivo de calendário.|
|GOPHER_TYPE_INLINE|Um arquivo embutido.|
|GOPHER_TYPE_UNKNOWN|O tipo de item é desconhecido.|
|GOPHER_TYPE_ASK|Um item Ask +.|
|GOPHER_TYPE_GOPHER_PLUS|Um item de Gopher +.|

##  <a name="operator_lpctstr"></a>  CGopherLocator::operator LPCTSTR

Esse operador de conversão útil fornece um método eficiente para acessar a cadeia de C terminada em nulo contida em um `CGopherLocator` objeto.

```
operator LPCTSTR () const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro de caractere para dados da cadeia de caracteres.

### <a name="remarks"></a>Comentários

Caracteres não é copiado; somente um ponteiro é retornado.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)
