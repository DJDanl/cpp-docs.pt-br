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
ms.openlocfilehash: bfbe03c5c81b2c7d6517dff7ce4e5f88b7c076bc
ms.sourcegitcommit: 975098222db3e8b297607cecaa1f504570a11799
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2018
ms.locfileid: "53178298"
---
# <a name="cmetafiledc-class"></a>Classe CMetaFileDC

Implementa um metarquivo do Windows, que contém uma sequência de comandos de interface (GDI) do dispositivo de gráficos que você pode repetir para criar um texto ou imagem desejada.

## <a name="syntax"></a>Sintaxe

```
class CMetaFileDC : public CDC
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMetaFileDC::CMetaFileDC](#cmetafiledc)|Constrói um objeto `CMetaFileDC`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMetaFileDC::Close](#close)|Fecha o contexto de dispositivo e cria um identificador de metarquivo.|
|[CMetaFileDC::CloseEnhanced](#closeenhanced)|Fecha um contexto de dispositivo de metarquivo avançado e cria um identificador de metarquivo avançado.|
|[CMetaFileDC::Create](#create)|Cria o contexto de dispositivo de metarquivo do Windows e anexa-o para o `CMetaFileDC` objeto.|
|[CMetaFileDC::CreateEnhanced](#createenhanced)|Cria um contexto de dispositivo de metarquivo para um metarquivo aprimorado de formato.|

## <a name="remarks"></a>Comentários

Para implementar um metarquivo do Windows, primeiro crie um `CMetaFileDC` objeto. Invocar o `CMetaFileDC` construtor, em seguida, chame o [Create](#create) função de membro, que cria um contexto de dispositivo de metarquivo do Windows e a anexa ao `CMetaFileDC` objeto.

Em seguida enviar o `CMetaFileDC` a sequência de comandos de GDI CDC que você pretenda para ele a repetição do objeto. Somente os comandos GDI que criem a saída, tais como `MoveTo` e `LineTo`, pode ser usado.

Depois que você enviou os comandos desejados para o metarquivo, chame o `Close` função de membro, que fecha os contextos de dispositivo de metarquivo e retorna um identificador de metarquivo. Em seguida, descarto a `CMetaFileDC` objeto.

[CDC::PlayMetaFile](../../mfc/reference/cdc-class.md#playmetafile) , em seguida, pode usar o identificador de metarquivo para reproduzir o metarquivo repetidamente. O metarquivo também pode ser manipulado por funções do Windows, como [CopyMetaFile](/windows/desktop/api/wingdi/nf-wingdi-copymetafilea), que copia um meta-arquivo para o disco.

Quando o metarquivo não for mais necessário, excluí-lo da memória com o [DeleteMetaFile](/windows/desktop/api/wingdi/nf-wingdi-deletemetafile) função do Windows.

Você também pode implementar o `CMetaFileDC` do objeto para que ele pode manipular ambos chamadas de saída e atributo GDI chamadas como `GetTextExtent`. Tal um metarquivo é mais flexível e podem mais facilmente reutilizar código GDI geral, o que geralmente consiste em uma combinação de chamadas de saída e de atributo. O `CMetaFileDC` classe herda os dois contextos de dispositivo `m_hDC` e `m_hAttribDC`, de CDC. O `m_hDC` contexto de dispositivo manipula toda [CDC](../../mfc/reference/cdc-class.md) GDI chamadas de saída e o `m_hAttribDC` contexto de dispositivo manipula todas as chamadas de atributo de CDC GDI. Normalmente, nesses contextos de dois dispositivo se referem ao mesmo dispositivo. No caso de `CMetaFileDC`, o controlador de domínio do atributo é definido como NULL por padrão.

Criar um segundo contexto de dispositivo que aponta para a tela, uma impressora ou dispositivo que não seja um metarquivo, em seguida, chame o `SetAttribDC` função de membro para associar o novo contexto de dispositivo com `m_hAttribDC`. Chamadas GDI para obter informações agora serão direcionadas para o novo `m_hAttribDC`. Chamadas GDI saída irá para `m_hDC`, que representa o metarquivo.

Para obter mais informações sobre `CMetaFileDC`, consulte [contextos de dispositivo](../../mfc/device-contexts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CDC](../../mfc/reference/cdc-class.md)

`CMetaFileDC`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

##  <a name="close"></a>  CMetaFileDC::Close

Fecha o contexto de dispositivo de metarquivo e cria um identificador de metarquivo do Windows que pode ser usado para reproduzir o metarquivo usando o [CDC::PlayMetaFile](../../mfc/reference/cdc-class.md#playmetafile) função de membro.

```
HMETAFILE Close();
```

### <a name="return-value"></a>Valor de retorno

Um HMETAFILE válido se a função for bem-sucedida; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

O identificador de metarquivo do Windows também pode ser usado para manipular o metarquivo com funções do Windows, como [CopyMetaFile](/windows/desktop/api/wingdi/nf-wingdi-copymetafilea).

Excluir o metarquivo após o uso, chamando o Windows [DeleteMetaFile](/windows/desktop/api/wingdi/nf-wingdi-deletemetafile) função.

##  <a name="closeenhanced"></a>  CMetaFileDC::CloseEnhanced

Fecha um contexto de dispositivo de metarquivo avançado e retorna um identificador que identifica um metarquivo aprimorado de formato.

```
HENHMETAFILE CloseEnhanced();
```

### <a name="return-value"></a>Valor de retorno

Um identificador de um metarquivo avançado, se for bem-sucedido; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

Um aplicativo pode usar o identificador de metarquivo avançado retornado por essa função para executar as seguintes tarefas:

- Exibir uma imagem armazenada em um metarquivo avançado

- Criar cópias de metarquivo avançado

- Enumerar, editar ou copiar registros individuais no metarquivo aprimorado

- Recuperar uma descrição opcional do metarquivo conteúdo do cabeçalho de metarquivo avançado

- Recuperar uma cópia do cabeçalho de metarquivo avançado

- Recuperar uma cópia binária do metarquivo aprimorado

- Enumerar as cores na paleta de opcional

- Converter um metarquivo aprimorado de formato em um metarquivo do Windows-format

Quando o aplicativo não precisa mais o identificador de metarquivo avançado, ele deve liberar o identificador chamando Win32 `DeleteEnhMetaFile` função.

##  <a name="cmetafiledc"></a>  CMetaFileDC::CMetaFileDC

Construir um `CMetaFileDC` objeto em duas etapas.

```
CMetaFileDC();
```

### <a name="remarks"></a>Comentários

Primeiro, chame `CMetaFileDC`, em seguida, chame `Create`, que cria o contexto de dispositivo de metarquivo do Windows e anexa-o para o `CMetaFileDC` objeto.

##  <a name="create"></a>  CMetaFileDC::Create

Construir um `CMetaFileDC` objeto em duas etapas.

```
BOOL Create(LPCTSTR lpszFilename = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszFilename*<br/>
Aponta para uma cadeia de caracteres terminada em nulo. Especifica o nome do arquivo do metarquivo para criar. Se *lpszFilename* for NULL, um metarquivo na memória novo é criado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Primeiro, chame o construtor `CMetaFileDC`, em seguida, chame `Create`, que cria o contexto de dispositivo de metarquivo do Windows e anexa-o para o `CMetaFileDC` objeto.

##  <a name="createenhanced"></a>  CMetaFileDC::CreateEnhanced

Cria um contexto de dispositivo para um metarquivo aprimorado de formato.

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
Aponta para uma cadeia de caracteres terminada em nulo. Especifica o nome do arquivo para o metarquivo avançado a ser criado. Se esse parâmetro for NULL, o metarquivo avançado é memória com base e seu conteúdo perdido quando o objeto é destruído ou quando o Win32 `DeleteEnhMetaFile` função é chamada.

*lpBounds*<br/>
Aponta para um [RECT](/windows/desktop/api/windef/ns-windef-tagrect) estrutura de dados ou uma [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica as dimensões em unidades HIMETRIC (em incrementos de.01 milímetro) da imagem a ser armazenado no metarquivo aprimorado.

*lpszDescription*<br/>
Aponta para uma cadeia de caracteres terminada em zero que especifica o nome do aplicativo que criou a imagem, bem como o título da imagem.

### <a name="return-value"></a>Valor de retorno

Um identificador de contexto do dispositivo para o metarquivo avançado, se for bem-sucedido; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

Esse controlador de domínio pode ser usado para armazenar uma imagem independente de dispositivo.

Windows usa o dispositivo de referência identificado pelo *pDCRef* parâmetro para registrar as unidades do dispositivo no qual uma imagem exibida originariamente e resolução. Se o *pDCRef* parâmetro for NULL, ele usa o dispositivo de exibição atual para referência.

Os membros da esquerda e superior do `RECT` dados estrutura apontada pela *lpBounds* parâmetro deve ser menor do que os membros direita e inferior, respectivamente. Pontos ao longo das bordas do retângulo são incluídos na imagem. Se *lpBounds* for NULL, a graphics device interface (GDI) calcula as dimensões do retângulo menor que pode colocar a imagem desenhada pelo aplicativo. O *lpBounds* parâmetro deve ser fornecido quando possível.

A cadeia de caracteres apontada pela *lpszDescription* parâmetro deve conter um caractere nulo entre o nome do aplicativo e o nome de imagem e deve terminar com dois caracteres nulos — por exemplo, "XYZ gráficos Editor\0Bald Eagle\0\0, "onde \0 representa o caractere nulo. Se *lpszDescription* for NULL, não há nenhuma entrada correspondente no cabeçalho de metarquivo avançado.

Aplicativos usam o controlador de domínio criado por essa função para armazenar uma imagem de elementos gráficos em um metarquivo avançado. O identificador que identifica esse controlador de domínio pode ser passado para qualquer função GDI.

Depois que um aplicativo armazena uma imagem em um metarquivo avançado, ele pode exibir a imagem em qualquer dispositivo de saída chamando o `CDC::PlayMetaFile` função. Ao exibir a imagem, o Windows usa o retângulo apontado para o *lpBounds* parâmetro e os dados de resolução do dispositivo de referência para posicionar e dimensionar a imagem. O contexto de dispositivo retornado por essa função contém os mesmos atributos padrão associados a qualquer novo controlador de domínio.

Os aplicativos devem usar o Win32 `GetWinMetaFileBits` função para converter um metarquivo avançado em formato de metarquivo do Windows mais antigo.

O nome do arquivo para o metarquivo avançado deve usar o. Extensão EMF.

## <a name="see-also"></a>Consulte também

[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

