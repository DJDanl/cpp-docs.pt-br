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
ms.openlocfilehash: 9ce95a712af6502bff2a2502582a7fa843bf9653
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506166"
---
# <a name="cgopherlocator-class"></a>Classe CGopherLocator

Obtém um "localizador" do Gopher de um servidor gopher, determina o tipo do localizador e disponibiliza o localizador para [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md).

> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind` eseusmembrosforampreteridasporquenãofuncionamnaplataformaWindowsXP,mascontinuarãofuncionando`CGopherLocator` em plataformas anteriores.

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
|[CGopherLocator::GetLocatorType](#getlocatortype)|Analisa um localizador do Gopher e determina seus atributos.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CGopherLocator:: Operator LPCTSTR](#operator_lpctstr)|Acessa diretamente os caracteres armazenados em um `CGopherLocator` objeto como uma cadeia de estilo C.|

## <a name="remarks"></a>Comentários

Um aplicativo deve obter o localizador de um servidor gopher antes de poder recuperar informações desse servidor. Depois de ter o localizador, ele deve tratar o localizador como um token opaco.

Cada localizador do Gopher tem atributos que determinam o tipo de arquivo ou servidor encontrado. Consulte [GetLocatorType](#getlocatortype) para obter uma lista de tipos de localizadores do Gopher.

Um aplicativo normalmente usa o localizador para chamadas para [CGopherFileFind:: FindFile](../../mfc/reference/cgopherfilefind-class.md#findfile) para recuperar uma informação específica.

Para saber mais sobre como `CGopherLocator` o funciona com as outras classes de Internet do MFC, confira o artigo [programação da Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CGopherLocator`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

##  <a name="cgopherlocator"></a>  CGopherLocator::CGopherLocator

Essa função de membro é chamada para criar `CGopherLocator` um objeto.

```
CGopherLocator(const CGopherLocator& ref);
```

### <a name="parameters"></a>Parâmetros

*ref*<br/>
Uma referência a um objeto `CGopherLocator` constante.

### <a name="remarks"></a>Comentários

Você nunca cria um `CGopherLocator` objeto diretamente. Em vez disso, chame [CGopherConnection:: CreateLocator](../../mfc/reference/cgopherconnection-class.md#createlocator) para criar e retornar um ponteiro `CGopherLocator` para o objeto.

##  <a name="getlocatortype"></a>  CGopherLocator::GetLocatorType

Chame essa função de membro para obter o tipo de localizador.

```
BOOL GetLocatorType(DWORD& dwRef) const;
```

### <a name="parameters"></a>Parâmetros

*dwRef*<br/>
Uma referência a um DWORD que receberá o tipo de localizador. Consulte **comentários** para uma tabela de tipos de localizador.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Os tipos possíveis são os seguintes:

|Valor|Significado|
|-----------|-------------|
|GOPHER_TYPE_TEXT_FILE|Um arquivo de texto ASCII.|
|GOPHER_TYPE_DIRECTORY|Um diretório de itens gopher adicionais.|
|GOPHER_TYPE_CSO|Um servidor de catálogo telefônico de CSO.|
|GOPHER_TYPE_ERROR|Indica uma condição de erro.|
|GOPHER_TYPE_MAC_BINHEX|Um arquivo do Macintosh no formato BINHEX.|
|GOPHER_TYPE_DOS_ARCHIVE|Um arquivo do DOS.|
|GOPHER_TYPE_UNIX_UUENCODED|Um arquivo UUENCODed.|
|GOPHER_TYPE_INDEX_SERVER|Um servidor de índice.|
|GOPHER_TYPE_TELNET|Um servidor Telnet.|
|GOPHER_TYPE_BINARY|Um arquivo binário.|
|GOPHER_TYPE_REDUNDANT|Um servidor duplicado. As informações contidas em são uma duplicata do servidor primário. O servidor primário é a última entrada de diretório que não tinha um tipo GOPHER_TYPE_REDUNDANT.|
|GOPHER_TYPE_TN3270|Um servidor TN3270.|
|GOPHER_TYPE_GIF|Um arquivo gráfico GIF.|
|GOPHER_TYPE_IMAGE|Um arquivo de imagem.|
|GOPHER_TYPE_BITMAP|Um arquivo de bitmap.|
|GOPHER_TYPE_MOVIE|Um arquivo de filme.|
|GOPHER_TYPE_SOUND|Um arquivo de som.|
|GOPHER_TYPE_HTML|Um documento HTML.|
|GOPHER_TYPE_PDF|Um arquivo PDF.|
|GOPHER_TYPE_CALENDAR|Um arquivo de calendário.|
|GOPHER_TYPE_INLINE|Um arquivo embutido.|
|GOPHER_TYPE_UNKNOWN|O tipo de item é desconhecido.|
|GOPHER_TYPE_ASK|Um Ask + item.|
|GOPHER_TYPE_GOPHER_PLUS|Um item do Gopher +.|

##  <a name="operator_lpctstr"></a>Operador CGopherLocator:: Operator LPCTSTR

Esse operador de conversão útil fornece um método eficiente para acessar a cadeia de caracteres C terminada em `CGopherLocator` nulo contida em um objeto.

```
operator LPCTSTR () const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro de caractere para os dados da cadeia de caracteres.

### <a name="remarks"></a>Comentários

Nenhum caractere copiado; apenas um ponteiro é retornado.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)
