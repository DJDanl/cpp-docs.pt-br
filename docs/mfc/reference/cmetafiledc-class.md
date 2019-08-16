---
title: Classe CMetaFileDC
ms.date: 11/04/2016
f1_keywords:
- CMetaFileDC
- AFXEXT/CMetaFileDC
- AFXEXT/CMetaFileDC::CMetaFileDC
- AFXEXT/CMetaFileDC::Close
- AFXEXT/CMetaFileDC::CloseEnhanced
- AFXEXT/CMetaFileDC::Create
- AFXEXT/CMetaFileDC::CreateEnhanced
helpviewer_keywords:
- CMetaFileDC [MFC], CMetaFileDC
- CMetaFileDC [MFC], Close
- CMetaFileDC [MFC], CloseEnhanced
- CMetaFileDC [MFC], Create
- CMetaFileDC [MFC], CreateEnhanced
ms.assetid: ffce60fa-4181-4d46-9832-25e46fad4db4
ms.openlocfilehash: 61e8442c085a5be0a7266409daf973bf63f52a7f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505511"
---
# <a name="cmetafiledc-class"></a>Classe CMetaFileDC

Implementa um metarquivo do Windows, que contém uma sequência de comandos da interface de dispositivo de gráficos (GDI) que você pode repetir para criar uma imagem ou um texto desejado.

## <a name="syntax"></a>Sintaxe

```
class CMetaFileDC : public CDC
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMetaFileDC::CMetaFileDC](#cmetafiledc)|Constrói um objeto `CMetaFileDC`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMetaFileDC::Close](#close)|Fecha o contexto do dispositivo e cria um identificador de metarquivo.|
|[CMetaFileDC::CloseEnhanced](#closeenhanced)|Fecha um contexto de dispositivo de metarquivo avançado e cria um identificador de metarquivo avançado.|
|[CMetaFileDC::Create](#create)|Cria o contexto do dispositivo de metarquivo do Windows e o `CMetaFileDC` anexa ao objeto.|
|[CMetaFileDC::CreateEnhanced](#createenhanced)|Cria um contexto de dispositivo de metarquivo para um metarquivo de formato avançado.|

## <a name="remarks"></a>Comentários

Para implementar um metarquivo do Windows, primeiro crie `CMetaFileDC` um objeto. Invoque o `CMetaFileDC` Construtor e, em seguida, chame a função de membro [Create](#create) , que cria um contexto de dispositivo de metarquivo do `CMetaFileDC` Windows e o anexa ao objeto.

Em seguida, `CMetaFileDC` envie ao objeto a sequência dos comandos do CDC GDI que você pretende reproduzir. Somente os comandos GDI que criam a saída, como `MoveTo` e `LineTo`, podem ser usados.

Depois de enviar os comandos desejados para o metarquivo, chame `Close` a função membro, que fecha os contextos de dispositivo de metarquivo e retorna um identificador de metarquivo. Em seguida, descarte `CMetaFileDC` o objeto.

[CDC::P laymetafile](../../mfc/reference/cdc-class.md#playmetafile) pode usar o identificador de metarquivo para reproduzir o metarquivo repetidamente. O metarquivo também pode ser manipulado por funções do Windows, como [CopyMetaFile](/windows/win32/api/wingdi/nf-wingdi-copymetafilew), que copia um metarquivo para o disco.

Quando o metarquivo não for mais necessário, exclua-o da memória com a função [DeleteMetaFile](/windows/win32/api/wingdi/nf-wingdi-deletemetafile) do Windows.

Você também pode implementar o `CMetaFileDC` objeto para que ele possa tratar as chamadas de saída e as chamadas GDI do `GetTextExtent`atributo, como. Esse tipo de metarquivo é mais flexível e pode reutilizar mais facilmente o código GDI geral, que geralmente consiste em uma combinação de chamadas de atributos e de saída. A `CMetaFileDC` classe herda dois contextos `m_hDC` de dispositivo e `m_hAttribDC`, do CDC. O `m_hDC` contexto do dispositivo manipula todas as chamadas de saída GDI `m_hAttribDC` do [CDC](../../mfc/reference/cdc-class.md) e o contexto do dispositivo trata todas as chamadas de atributo GDI do CDC. Normalmente, esses dois contextos de dispositivo fazem referência ao mesmo dispositivo. No caso do `CMetaFileDC`, o atributo DC é definido como NULL por padrão.

Crie um segundo contexto de dispositivo que aponte para a tela, uma impressora ou um dispositivo que não seja um metarquivo e, `SetAttribDC` em seguida, chame a função de membro para `m_hAttribDC`associar o novo contexto de dispositivo. As chamadas GDI para informações agora serão direcionadas para o `m_hAttribDC`novo. As chamadas GDI de saída vão `m_hDC`para, que representa o metarquivo.

Para obter mais informações `CMetaFileDC`sobre o, consulte contextos de [dispositivo](../../mfc/device-contexts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CDC](../../mfc/reference/cdc-class.md)

`CMetaFileDC`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext. h

##  <a name="close"></a>CMetaFileDC:: fechar

Fecha o contexto do dispositivo de metarquivo e cria um identificador de metarquivo do Windows que pode ser usado para reproduzir o metarquivo usando a função de membro [CDC::P laymetafile](../../mfc/reference/cdc-class.md#playmetafile) .

```
HMETAFILE Close();
```

### <a name="return-value"></a>Valor de retorno

Um HMETAFILE válido se a função for bem-sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

O identificador de metarquivo do Windows também pode ser usado para manipular o metarquivo com funções do Windows, como [CopyMetaFile](/windows/win32/api/wingdi/nf-wingdi-copymetafilew).

Exclua o metarquivo após o uso chamando a função [DeleteMetaFile](/windows/win32/api/wingdi/nf-wingdi-deletemetafile) do Windows.

##  <a name="closeenhanced"></a>CMetaFileDC::CloseEnhanced

Fecha um contexto de dispositivo de metarquivo avançado e retorna um identificador que identifica um metarquivo de formato avançado.

```
HENHMETAFILE CloseEnhanced();
```

### <a name="return-value"></a>Valor de retorno

Um identificador de um metarquivo avançado, se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Um aplicativo pode usar o identificador de metarquivo avançado retornado por essa função para executar as seguintes tarefas:

- Exibir uma imagem armazenada em um metarquivo avançado

- Criar cópias do metarquivo avançado

- Enumerar, editar ou copiar registros individuais no metarquivo avançado

- Recuperar uma descrição opcional do conteúdo do metarquivo do cabeçalho Enhanced-Metafile

- Recuperar uma cópia do cabeçalho Enhanced-Metafile

- Recuperar uma cópia binária do metarquivo avançado

- Enumerar as cores na paleta opcional

- Converter um metarquivo de formato avançado em um metarquivo de formato do Windows

Quando o aplicativo não precisar mais do identificador de metarquivo avançado, ele deverá liberar o identificador chamando a função `DeleteEnhMetaFile` do Win32.

##  <a name="cmetafiledc"></a>  CMetaFileDC::CMetaFileDC

Construa um `CMetaFileDC` objeto em duas etapas.

```
CMetaFileDC();
```

### <a name="remarks"></a>Comentários

Primeiro, chame `CMetaFileDC`e, em `Create`seguida, chame, que cria o contexto do dispositivo de metarquivo do Windows `CMetaFileDC` e o anexa ao objeto.

##  <a name="create"></a>CMetaFileDC:: criar

Construa um `CMetaFileDC` objeto em duas etapas.

```
BOOL Create(LPCTSTR lpszFilename = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszFilename*<br/>
Aponta para uma cadeia de caracteres de caractere terminada em nulo. Especifica o nome do arquivo do metarquivo a ser criado. Se *lpszFileName* for NULL, um novo metarquivo na memória será criado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Primeiro, chame o construtor `CMetaFileDC`e, em `Create`seguida, chame, que cria o contexto do dispositivo de metarquivo do Windows `CMetaFileDC` e o anexa ao objeto.

##  <a name="createenhanced"></a>CMetaFileDC:: createenhancemented

Cria um contexto de dispositivo para um metarquivo de formato avançado.

```
BOOL CreateEnhanced(
    CDC* pDCRef,
    LPCTSTR lpszFileName,
    LPCRECT lpBounds,
    LPCTSTR lpszDescription);
```

### <a name="parameters"></a>Parâmetros

*pDCRef*<br/>
Identifica um dispositivo de referência para o metarquivo avançado.

*lpszFileName*<br/>
Aponta para uma cadeia de caracteres de caractere terminada em nulo. Especifica o nome do arquivo para o metarquivo avançado a ser criado. Se esse parâmetro for nulo, o metarquivo avançado será baseado na memória e seu conteúdo será perdido quando o objeto for destruído ou quando `DeleteEnhMetaFile` a função do Win32 for chamada.

*lpBounds*<br/>
Aponta para uma estrutura de dados [Rect](/windows/win32/api/windef/ns-windef-rect) ou um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que especifica as dimensões em unidades HIMETRIC (em incrementos de 0,01 a milímetros) da imagem a ser armazenada no metarquivo avançado.

*lpszDescription*<br/>
Aponta para uma cadeia de caracteres terminada em zero que especifica o nome do aplicativo que criou a imagem, bem como o título da imagem.

### <a name="return-value"></a>Valor de retorno

Um identificador do contexto do dispositivo para o metarquivo avançado, se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse DC pode ser usado para armazenar uma imagem independente do dispositivo.

O Windows usa o dispositivo de referência identificado pelo parâmetro *pDCRef* para registrar a resolução e as unidades do dispositivo no qual uma imagem apareceu originalmente. Se o parâmetro *pDCRef* for NULL, ele usará o dispositivo de vídeo atual para referência.

Os membros esquerdo e superior da `RECT` estrutura de dados apontados pelo parâmetro *lpBounds* devem ser menores do que os membros direito e inferior, respectivamente. Os pontos ao longo das bordas do retângulo são incluídos na imagem. Se *lpBounds* for NULL, a interface de dispositivo de gráficos (GDI) computa as dimensões do menor retângulo que podem incluir a imagem desenhada pelo aplicativo. O parâmetro *lpBounds* deve ser fornecido sempre que possível.

A cadeia de caracteres apontada pelo parâmetro *lpszDescription* deve conter um caractere nulo entre o nome do aplicativo e o nome da imagem e deve terminar com dois caracteres nulos — por exemplo, "XYZ Graphics Editor\0Bald Eagle\0\0", onde \ 0 representa o caractere nulo. Se *lpszDescription* for nulo, não haverá nenhuma entrada correspondente no cabeçalho Enhanced-Metafile.

Os aplicativos usam o DC criado por essa função para armazenar uma imagem gráfica em um metarquivo avançado. O identificador que identifica esse controlador de domínio pode ser passado para qualquer função GDI.

Depois que um aplicativo armazena uma imagem em um metarquivo avançado, ele pode exibir a imagem em qualquer dispositivo de saída chamando `CDC::PlayMetaFile` a função. Ao exibir a imagem, o Windows usa o retângulo apontado pelo parâmetro *lpBounds* e os dados de resolução do dispositivo de referência para posicionar e dimensionar a imagem. O contexto do dispositivo retornado por essa função contém os mesmos atributos padrão associados a qualquer novo DC.

Os aplicativos devem usar a `GetWinMetaFileBits` função do Win32 para converter um metarquivo avançado para o formato de metarquivo do Windows mais antigo.

O nome do arquivo para o metarquivo avançado deve usar o. Extensão EMF.

## <a name="see-also"></a>Consulte também

[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
