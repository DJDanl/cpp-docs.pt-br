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
ms.openlocfilehash: 0919dacfd758df39064c5381690e9e23a029fcd1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369958"
---
# <a name="cmetafiledc-class"></a>Classe CMetaFileDC

Implementa um metaarquivo do Windows, que contém uma seqüência de comandos GDI (Graphics Device Interface, interface de dispositivo gráfico) que você pode reproduzir para criar uma imagem ou texto desejado.

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
|[CMetaFileDC::Fechar](#close)|Fecha o contexto do dispositivo e cria uma alça de metaarquivo.|
|[CMetaFileDC::CloseEnhanced](#closeenhanced)|Fecha um contexto de dispositivo de metaarquivos aprimorado e cria uma alça de metaarquivo aprimorada.|
|[CMetaFileDC::Criar](#create)|Cria o contexto do dispositivo de metaarquivo do Windows e o anexa ao `CMetaFileDC` objeto.|
|[CMetaFileDC::CreateEnhanced](#createenhanced)|Cria um contexto de dispositivo de metaarquivos para um metaarquivo de formato aprimorado.|

## <a name="remarks"></a>Comentários

Para implementar um metaarquivo do `CMetaFileDC` Windows, primeiro crie um objeto. Invoque o `CMetaFileDC` construtor e, em seguida, chame a função [Criar](#create) membro, `CMetaFileDC` que cria um contexto de dispositivo de metaarquivo do Windows e anexa-o ao objeto.

Em seguida, envie ao `CMetaFileDC` objeto a seqüência de comandos CDC GDI que você pretende que ele reproduza. Somente os comandos GDI que `MoveTo` criam `LineTo`saída, como e , podem ser usados.

Depois de enviar os comandos desejados para `Close` o metaarquivo, ligue para a função membro, que fecha os contextos do dispositivo de metaarquivo e retorna uma alça de metaarquivo. Então elimine `CMetaFileDC` o objeto.

[CDC::PlayMetaFile](../../mfc/reference/cdc-class.md#playmetafile) pode usar a alça de metaarquivo para reproduzir o metaarquivo repetidamente. O metaarquivo também pode ser manipulado por funções do Windows, como [CopyMetaFile](/windows/win32/api/wingdi/nf-wingdi-copymetafilew), que copia um metaarquivo para disco.

Quando o metaarquivo não for mais necessário, exclua-o da memória com a função [DeleteMetaFile](/windows/win32/api/wingdi/nf-wingdi-deletemetafile) Windows.

Você também pode `CMetaFileDC` implementar o objeto para que ele possa lidar `GetTextExtent`com chamadas de saída e atribuir chamadas GDI, como . Esse metaarquivo é mais flexível e pode reutilizar mais facilmente o código GDI geral, que muitas vezes consiste em uma mistura de chamadas de saída e atributos. A `CMetaFileDC` classe herda dois `m_hDC` contextos de dispositivos, e `m_hAttribDC`, do CDC. O `m_hDC` contexto do dispositivo lida com todas `m_hAttribDC` as chamadas de saída do [CDC](../../mfc/reference/cdc-class.md) GDI e o contexto do dispositivo lida com todas as chamadas de atributos DO CDC GDI. Normalmente, esses dois contextos de dispositivo se referem ao mesmo dispositivo. No caso `CMetaFileDC`de, o atributo DC é definido como NULL por padrão.

Crie um segundo contexto de dispositivo que aponte para a tela, uma `SetAttribDC` impressora ou dispositivo que `m_hAttribDC`não seja um metaarquivo e, em seguida, ligue para a função do membro para associar o novo contexto do dispositivo com . Os pedidos de informações do GDI `m_hAttribDC`serão agora direcionados para o novo . As chamadas GDI `m_hDC`de saída irão para , o que representa o metaarquivo.

Para obter `CMetaFileDC`mais informações sobre , consulte [Contextos do dispositivo](../../mfc/device-contexts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CDC](../../mfc/reference/cdc-class.md)

`CMetaFileDC`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="cmetafiledcclose"></a><a name="close"></a>CMetaFileDC::Fechar

Fecha o contexto do dispositivo de metaarquivo e cria uma alça de metaarquivo do Windows que pode ser usada para reproduzir o metaarquivo usando a função de membro [CDC::PlayMetaFile.](../../mfc/reference/cdc-class.md#playmetafile)

```
HMETAFILE Close();
```

### <a name="return-value"></a>Valor retornado

Um HMETAFILE válido se a função for bem sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

O cabo de metaarquivo do Windows também pode ser usado para manipular o metaarquivo com funções do Windows, como [CopyMetaFile](/windows/win32/api/wingdi/nf-wingdi-copymetafilew).

Exclua o metaarquivo após o uso, chamando a função [Windows DeleteMetaFile.](/windows/win32/api/wingdi/nf-wingdi-deletemetafile)

## <a name="cmetafiledccloseenhanced"></a><a name="closeenhanced"></a>CMetaFileDC::CloseEnhanced

Fecha um contexto de dispositivo de metaarquivo aprimorado e retorna uma alça que identifica um metaarquivo de formato aprimorado.

```
HENHMETAFILE CloseEnhanced();
```

### <a name="return-value"></a>Valor retornado

Uma alça de um metaarquivo aprimorado, se bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Um aplicativo pode usar a alça de metaarquivo aprimorada retornada por esta função para executar as seguintes tarefas:

- Exibir uma imagem armazenada em um metaarquivo aprimorado

- Criar cópias do metaarquivo aprimorado

- Enumerar, editar ou copiar registros individuais no metaarquivo aprimorado

- Recupere uma descrição opcional do conteúdo do metaarquivo do cabeçalho de metaarquivo aprimorado

- Recupere uma cópia do cabeçalho de metaarquivo aprimorado

- Recupere uma cópia binária do metaarquivo aprimorado

- Enumerar as cores na paleta opcional

- Converta um metaarquivo de formato aprimorado em um metaarquivo em formato Windows

Quando o aplicativo não precisar mais da alça de metaarquivo aprimorada, `DeleteEnhMetaFile` ele deve liberar a alça chamando a função Win32.

## <a name="cmetafiledccmetafiledc"></a><a name="cmetafiledc"></a>CMetaFileDC::CMetaFileDC

Construa `CMetaFileDC` um objeto em dois passos.

```
CMetaFileDC();
```

### <a name="remarks"></a>Comentários

Primeiro, `CMetaFileDC`ligue, `Create`depois chame, que cria o contexto do `CMetaFileDC` dispositivo de metaarquivo do Windows e o anexe ao objeto.

## <a name="cmetafiledccreate"></a><a name="create"></a>CMetaFileDC::Criar

Construa `CMetaFileDC` um objeto em dois passos.

```
BOOL Create(LPCTSTR lpszFilename = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszNome de arquivo*<br/>
Aponta para uma seqüência de caracteres com término nulo. Especifica o nome de arquivo do metaarquivo a ser criado. Se *lpszFilename* for NULL, um novo metaarquivo na memória será criado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Primeiro, ligue para `CMetaFileDC`o `Create`construtor, depois chame, que cria o contexto `CMetaFileDC` do dispositivo de metaarquivo do Windows e o anexe ao objeto.

## <a name="cmetafiledccreateenhanced"></a><a name="createenhanced"></a>CMetaFileDC::CreateEnhanced

Cria um contexto de dispositivo para um metaarquivo de formato aprimorado.

```
BOOL CreateEnhanced(
    CDC* pDCRef,
    LPCTSTR lpszFileName,
    LPCRECT lpBounds,
    LPCTSTR lpszDescription);
```

### <a name="parameters"></a>Parâmetros

*pDCRef*<br/>
Identifica um dispositivo de referência para o metaarquivo aprimorado.

*lpszFileName*<br/>
Aponta para uma seqüência de caracteres com término nulo. Especifica o nome do arquivo para o metaarquivo aprimorado a ser criado. Se este parâmetro for NULO, o metaarquivo aprimorado será baseado em memória e seu `DeleteEnhMetaFile` conteúdo perdido quando o objeto é destruído ou quando a função Win32 é chamada.

*Lpbounds*<br/>
Aponta para uma estrutura de dados [RECT](/windows/win32/api/windef/ns-windef-rect) ou um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que especifica as dimensões em unidades HIMETRIC (em incrementos de 01 milímetros) da imagem a ser armazenada no metaarquivo aprimorado.

*lpszDescrição*<br/>
Aponta para uma seqüência de terminação zero que especifica o nome do aplicativo que criou a imagem, bem como o título da imagem.

### <a name="return-value"></a>Valor retornado

Uma alça do contexto do dispositivo para o metaarquivo aprimorado, se bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este DC pode ser usado para armazenar uma imagem independente do dispositivo.

O Windows usa o dispositivo de referência identificado pelo parâmetro *pDCRef* para registrar a resolução e as unidades do dispositivo em que uma imagem apareceu originalmente. Se o parâmetro *pDCRef* for NULL, ele usará o dispositivo de exibição atual como referência.

Os membros esquerdo salina e superior da `RECT` estrutura de dados apontados pelo parâmetro *lpBounds* devem ser menores do que os membros da direita e inferior, respectivamente. Pontos ao longo das bordas do retângulo estão incluídos na imagem. Se *lpBounds* for NULL, a interface do dispositivo gráfico (GDI) calcula as dimensões do menor retângulo que pode envolver a imagem desenhada pelo aplicativo. O parâmetro *lpBounds* deve ser fornecido sempre que possível.

A seqüência apontada pelo parâmetro *lpszDescription* deve conter um caractere nulo entre o nome do aplicativo e o nome da imagem e deve terminar com dois caracteres nulos — por exemplo, "XYZ Graphics Editor\0Bald Eagle\0\0", onde \0 representa o caractere nulo. Se *lpszDescription* for NULL, não haverá entrada correspondente no cabeçalho de metaarquivo aprimorado.

Os aplicativos usam o DC criado por esta função para armazenar uma imagem gráfica em um metaarquivo aprimorado. A alça que identifica este DC pode ser passada para qualquer função GDI.

Depois que um aplicativo armazena uma imagem em um metaarquivo aprimorado, ele `CDC::PlayMetaFile` pode exibir a imagem em qualquer dispositivo de saída chamando a função. Ao exibir a imagem, o Windows usa o retângulo apontado pelo parâmetro *lpBounds* e os dados de resolução do dispositivo de referência para posicionar e dimensionar a imagem. O contexto do dispositivo retornado por esta função contém os mesmos atributos padrão associados a qualquer nova DC.

Os aplicativos devem usar `GetWinMetaFileBits` a função Win32 para converter um metaarquivo aprimorado para o formato de metaarquivo mais antigo do Windows.

O nome do arquivo para o metaarquivo aprimorado deve usar o . Extensão EMF.

## <a name="see-also"></a>Confira também

[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
