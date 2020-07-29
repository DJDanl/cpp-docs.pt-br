---
title: 'Controles ActiveX MFC: serializando'
ms.date: 09/12/2018
f1_keywords:
- _wVerMinor
- DoPropExchange
- _wVerMajor
helpviewer_keywords:
- MFC ActiveX controls [MFC], version support
- wVerMinor global constant [MFC]
- GetVersion method [MFC]
- ExchangeVersion method [MFC]
- MFC ActiveX controls [MFC], serializing
- DoPropExchange method [MFC]
- versioning ActiveX controls
- wVerMajor global constant
ms.assetid: 9d57c290-dd8c-4853-b552-6f17f15ebedd
ms.openlocfilehash: f5e3b4bdf203f90b3550a2521ba51ba451cf3a46
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225014"
---
# <a name="mfc-activex-controls-serializing"></a>Controles ActiveX MFC: serializando

Este artigo discute como serializar um controle ActiveX. A serialização é o processo de leitura ou gravação em um meio de armazenamento persistente, como um arquivo de disco. A biblioteca do Microsoft Foundation Class (MFC) fornece suporte interno para serialização na classe `CObject` . `COleControl`estende esse suporte a controles ActiveX por meio do uso de um mecanismo de troca de propriedade.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

A serialização para controles ActiveX é implementada por meio da substituição de [COleControl::D opropexchange](reference/colecontrol-class.md#dopropexchange). Essa função, chamada durante o carregamento e salvamento do objeto de controle, armazena todas as propriedades implementadas com uma variável de membro ou uma variável de membro com notificação de alteração.

Os tópicos a seguir abordam os principais problemas relacionados à serialização de um controle ActiveX:

- Implementando `DoPropExchange` a função para serializar seu objeto de controle

- [Personalizando o processo de serialização](#_core_customizing_the_default_behavior_of_dopropexchange)

- [Implementando o suporte à versão](#_core_implementing_version_support)

## <a name="implementing-the-dopropexchange-function"></a><a name="_core_implementing_the_dopropexchange_function"></a>Implementando a função DoPropExchange

Quando você usa o assistente de controle ActiveX para gerar o projeto de controle, várias funções de manipulador padrão são adicionadas automaticamente à classe Control, incluindo a implementação padrão de [COleControl::D opropexchange](reference/colecontrol-class.md#dopropexchange). O exemplo a seguir mostra o código adicionado às classes criadas com o assistente de controle ActiveX:

[!code-cpp[NVC_MFC_AxUI#43](codesnippet/cpp/mfc-activex-controls-serializing_1.cpp)]

Se você quiser tornar uma propriedade persistente, modifique `DoPropExchange` adicionando uma chamada à função de troca de propriedade. O exemplo a seguir demonstra a serialização de uma propriedade booleana CircleShape personalizada, em que a propriedade CircleShape tem um valor padrão de **true**:

[!code-cpp[NVC_MFC_AxSer#1](codesnippet/cpp/mfc-activex-controls-serializing_2.cpp)]
[!code-cpp[NVC_MFC_AxSer#2](codesnippet/cpp/mfc-activex-controls-serializing_3.cpp)]

A tabela a seguir lista as funções de troca de propriedade possíveis que você pode usar para serializar as propriedades do controle:

|Funções de troca de propriedades|Finalidade|
|---------------------------------|-------------|
|**PX_Blob ()**|Serializa uma propriedade de dados BLOB (objeto binário grande) de tipo.|
|**PX_Bool ()**|Serializa uma propriedade booliana de tipo.|
|**PX_Color ()**|Serializa uma propriedade de cor de tipo.|
|**PX_Currency ()**|Serializa um tipo de propriedade **CY** (Currency).|
|**PX_Double ()**|Serializa uma propriedade Type **`double`** .|
|**PX_Font ()**|Serializa uma propriedade de tipo de fonte.|
|**PX_Float ()**|Serializa uma propriedade Type **`float`** .|
|**PX_IUnknown ()**|Serializa uma propriedade do tipo `LPUNKNOWN` .|
|**PX_Long ()**|Serializa uma propriedade Type **`long`** .|
|**PX_Picture ()**|Serializa uma propriedade de imagem de tipo.|
|**PX_Short ()**|Serializa uma propriedade Type **`short`** .|
|**PXstring( )**|Serializa uma propriedade Type `CString` .|
|**PX_ULong ()**|Serializa uma propriedade **ULONG** de tipo.|
|**PX_UShort ()**|Serializa uma propriedade **UShort** de tipo.|

Para obter mais informações sobre essas funções de troca de propriedades, consulte [persistência de controles OLE](reference/persistence-of-ole-controls.md) na *referência do MFC*.

## <a name="customizing-the-default-behavior-of-dopropexchange"></a><a name="_core_customizing_the_default_behavior_of_dopropexchange"></a>Personalizando o comportamento padrão de DoPropExchange

A implementação padrão de `DoPropertyExchange` (conforme mostrado no tópico anterior) faz uma chamada para classe base `COleControl` . Isso serializa o conjunto de propriedades com suporte automático pelo `COleControl` , que usa mais espaço de armazenamento do que a serialização apenas das propriedades personalizadas do controle. A remoção dessa chamada permite que seu objeto Serialize somente as propriedades que você considera importantes. Qualquer propriedade de estoque que o controle implementou não será serializada ao salvar ou carregar o objeto de controle, a menos que você adicione explicitamente **PX_** chamadas para eles.

## <a name="implementing-version-support"></a><a name="_core_implementing_version_support"></a>Implementando o suporte à versão

O suporte à versão permite que um controle ActiveX revisado adicione novas propriedades persistentes e ainda seja capaz de detectar e carregar o estado persistente criado por uma versão anterior do controle. Para disponibilizar uma versão de controle como parte de seus dados persistentes, chame [COleControl:: ExchangeVersion](reference/colecontrol-class.md#exchangeversion) na função do controle `DoPropExchange` . Essa chamada será inserida automaticamente se o controle ActiveX tiver sido criado usando o assistente de controle ActiveX. Ela poderá ser removida se o suporte à versão não for necessário. No entanto, o custo no tamanho do controle é muito pequeno (4 bytes) para a flexibilidade adicional fornecida pelo suporte à versão.

Se o controle não foi criado com o assistente de controle ActiveX, adicione uma chamada para `COleControl::ExchangeVersion` inserindo a seguinte linha no início da `DoPropExchange` função (antes da chamada para `COleControl::DoPropExchange` ):

[!code-cpp[NVC_MFC_AxSer#1](codesnippet/cpp/mfc-activex-controls-serializing_2.cpp)]
[!code-cpp[NVC_MFC_AxSer#3](codesnippet/cpp/mfc-activex-controls-serializing_4.cpp)]

Você pode usar qualquer **DWORD** como o número de versão. Projetos gerados pelo assistente de controle ActiveX usam `_wVerMinor` e `_wVerMajor` como o padrão. Essas são constantes globais definidas no arquivo de implementação da classe de controle ActiveX do projeto. No restante da sua `DoPropExchange` função, você pode chamar [CPropExchange:: GetVersion](reference/cpropexchange-class.md#getversion) a qualquer momento para recuperar a versão que você está salvando ou recuperando.

No exemplo a seguir, a versão 1 deste controle de exemplo tem apenas uma propriedade "liberou". A versão 2 adiciona uma propriedade "OriginalDate". Se o controle for instruído a carregar o estado persistente da versão antiga, ele inicializa a variável de membro para a nova propriedade para um valor padrão.

[!code-cpp[NVC_MFC_AxSer#4](codesnippet/cpp/mfc-activex-controls-serializing_5.cpp)]
[!code-cpp[NVC_MFC_AxSer#3](codesnippet/cpp/mfc-activex-controls-serializing_4.cpp)]

Por padrão, um controle "converte" dados antigos no formato mais recente. Por exemplo, se a versão 2 de um controle carregar dados que foram salvos pela versão 1, ele gravará o formato da versão 2 quando ele for salvo novamente. Se você quiser que o controle salve dados no formato última leitura, passe **false** como um terceiro parâmetro ao chamar `ExchangeVersion` . Esse terceiro parâmetro é opcional e é **true** por padrão.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](mfc-activex-controls.md)
