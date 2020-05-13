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
ms.openlocfilehash: d804486b612906f537b6ed1665dfc0cec5149826
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364545"
---
# <a name="mfc-activex-controls-serializing"></a>Controles ActiveX MFC: serializando

Este artigo discute como serializar um controle ActiveX. Serialização é o processo de leitura ou escrita para um meio de armazenamento persistente, como um arquivo de disco. A Biblioteca Microsoft Foundation Class (MFC) oferece suporte `CObject`integrado para serialização em classe . `COleControl`estende esse suporte aos controles ActiveX através do uso de um mecanismo de troca de propriedades.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

A serialização para controles ActiveX é implementada substituindo [COleControl::DoPropExchange](../mfc/reference/colecontrol-class.md#dopropexchange). Esta função, chamada durante o carregamento e a salvação do objeto de controle, armazena todas as propriedades implementadas com uma variável de membro ou uma variável de membro com notificação de alteração.

Os tópicos a seguir abrangem os principais problemas relacionados à serialização de um controle ActiveX:

- Implementando `DoPropExchange` função para serializar seu objeto de controle

- [Personalização do Processo de Serialização](#_core_customizing_the_default_behavior_of_dopropexchange)

- [Implementando suporte à versão](#_core_implementing_version_support)

## <a name="implementing-the-dopropexchange-function"></a><a name="_core_implementing_the_dopropexchange_function"></a>Implementando a função DoPropExchange

Quando você usa o ActiveX Control Wizard para gerar o projeto de controle, várias funções de manipulador padrão são automaticamente adicionadas à classe de controle, incluindo a implementação padrão do [COleControl::DoPropExchange](../mfc/reference/colecontrol-class.md#dopropexchange). O exemplo a seguir mostra o código adicionado às classes criadas com o Assistente de Controle ActiveX:

[!code-cpp[NVC_MFC_AxUI#43](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_1.cpp)]

Se você quiser tornar uma `DoPropExchange` propriedade persistente, modifique adicionando uma chamada à função de troca de propriedades. O exemplo a seguir demonstra a serialização de uma propriedade Boolean CircleShape personalizada, onde a propriedade CircleShape tem um valor padrão de **TRUE**:

[!code-cpp[NVC_MFC_AxSer#1](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_2.cpp)]
[!code-cpp[NVC_MFC_AxSer#2](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_3.cpp)]

A tabela a seguir lista as possíveis funções de troca de propriedades que você pode usar para serializar as propriedades do controle:

|Funções de troca de propriedades|Finalidade|
|---------------------------------|-------------|
|**PX_Blob.**|Serializa uma propriedade de dados Binário Large Object (BLOB) do tipo Binary Object .|
|**PX_Bool.**|Serializa uma propriedade booleana do tipo.|
|**PX_Color.**|Serializa uma propriedade de cor de tipo.|
|**PX_Currency.**|Serializa uma propriedade **tipo CY** (moeda).|
|**PX_Double.**|Serializa um tipo de propriedade **dupla.**|
|**PX_Font.**|Serializa uma propriedade do tipo Fonte.|
|**PX_Float.**|Serializa uma propriedade **flutuante** tipo.|
|**PX_IUnknown.**|Serializa uma propriedade `LPUNKNOWN`do tipo .|
|**PX_Long.**|Serializa uma propriedade **tipo longa.**|
|**PX_Picture.**|Serializa uma propriedade tipo Imagem.|
|**PX_Short.**|Serializa um tipo de propriedade **curta.**|
|**PXstring**|Serializa uma `CString` propriedade do tipo.|
|**PX_ULong.**|Serializa uma propriedade **ULONG** tipo.|
|**PX_UShort.**|Serializa uma propriedade **USHORT** tipo.|

Para obter mais informações sobre essas funções de troca de propriedades, consulte [Persistência de Controles OLE](../mfc/reference/persistence-of-ole-controls.md) na *Referência MFC*.

## <a name="customizing-the-default-behavior-of-dopropexchange"></a><a name="_core_customizing_the_default_behavior_of_dopropexchange"></a>Personalizando o comportamento padrão do DoPropExchange

A implementação `DoPropertyExchange` padrão de (como mostrado no tópico `COleControl`anterior) faz uma chamada para a classe base . Isso serializa o conjunto de propriedades `COleControl`automaticamente suportadas por , que usa mais espaço de armazenamento do que serializar apenas as propriedades personalizadas do controle. A remoção desta chamada permite que seu objeto serialize apenas as propriedades que você considera importantes. Qualquer propriedade de estoque afirma que o controle implementado não será serializado ao salvar ou carregar o objeto de controle, a menos que você adicione explicitamente **PX_** chamadas para eles.

## <a name="implementing-version-support"></a><a name="_core_implementing_version_support"></a>Implementando suporte à versão

O suporte à versão permite que um controle ActiveX revisado adicione novas propriedades persistentes e ainda seja capaz de detectar e carregar o estado persistente criado por uma versão anterior do controle. Para disponibilizar a versão de um controle como parte de seus dados persistentes, ligue `DoPropExchange` para [COleControl::ExchangeVersion](../mfc/reference/colecontrol-class.md#exchangeversion) na função do controle. Esta chamada é automaticamente inserida se o controle ActiveX foi criado usando o Assistente de Controle ActiveX. Ele pode ser removido se o suporte à versão não for necessário. No entanto, o custo no tamanho do controle é muito pequeno (4 bytes) para a flexibilidade adicional que o suporte à versão proporciona.

Se o controle não foi criado com o Assistente `COleControl::ExchangeVersion` de Controle ActiveX, adicione uma `DoPropExchange` chamada ao inserir `COleControl::DoPropExchange`a seguinte linha no início da sua função (antes da chamada para ):

[!code-cpp[NVC_MFC_AxSer#1](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_2.cpp)]
[!code-cpp[NVC_MFC_AxSer#3](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_4.cpp)]

Você pode usar qualquer **DWORD** como número da versão. Projetos gerados pelo activex `_wVerMinor` `_wVerMajor` control wizard usam e como padrão. Essas são constantes globais definidas no arquivo de implementação da classe de controle ActiveX do projeto. No restante da `DoPropExchange` função, você pode chamar [CPropExchange::GetVersion](../mfc/reference/cpropexchange-class.md#getversion) a qualquer momento para recuperar a versão que você está salvando ou recuperando.

No exemplo a seguir, a versão 1 deste controle de amostra tem apenas uma propriedade "ReleaseDate". A versão 2 adiciona uma propriedade "OriginalDate". Se o controle for instruído a carregar o estado persistente da versão antiga, ele inicializa a variável membro para a nova propriedade para um valor padrão.

[!code-cpp[NVC_MFC_AxSer#4](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_5.cpp)]
[!code-cpp[NVC_MFC_AxSer#3](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_4.cpp)]

Por padrão, um controle "converte" dados antigos para o formato mais recente. Por exemplo, se a versão 2 de um controle carregar dados que foram salvos pela versão 1, ele gravará o formato da versão 2 quando for salvo novamente. Se você quiser que o controle salve dados **FALSE** no formato lido pela `ExchangeVersion`última vez, passe FALSE como um terceiro parâmetro ao ligar . Este terceiro parâmetro é opcional e é **VERDADEIRO** por padrão.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
