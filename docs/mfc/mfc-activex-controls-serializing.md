---
title: 'Controles ActiveX MFC: Serializando | Microsoft Docs'
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- _wVerMinor
- DoPropExchange
- _wVerMajor
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3be523feaacb403076f2c066943ca55ace958dce
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46401830"
---
# <a name="mfc-activex-controls-serializing"></a>Controles ActiveX MFC: serializando

Este artigo descreve como serializar um controle ActiveX. A serialização é o processo de leitura ou gravação em uma mídia de armazenamento persistente, como um arquivo de disco. A biblioteca Microsoft Foundation Class (MFC) fornece suporte interno para a serialização na classe `CObject`. `COleControl` amplia esse suporte para controles ActiveX com o uso de um mecanismo de troca de propriedade.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem as ActiveX, consulte [controles ActiveX](activex-controls.md).

Serialização para controles ActiveX é implementada por meio da substituição [COleControl::DoPropExchange](../mfc/reference/colecontrol-class.md#dopropexchange). Essa função, chamado durante o carregamento e salvando do objeto de controle, armazena todas as propriedades implementadas com uma variável de membro ou uma variável de membro com a notificação de alteração.

Os tópicos a seguir abordam os principais problemas relacionados a serialização de um controle ActiveX:

- Implementando `DoPropExchange` função para serializar o objeto de controle

- [Personalizando o processo de serialização](#_core_customizing_the_default_behavior_of_dopropexchange)

- [Implementando o suporte de versão](#_core_implementing_version_support)

##  <a name="_core_implementing_the_dopropexchange_function"></a> Implementando a função DoPropExchange

Quando você usa o Assistente de controle ActiveX para gerar o projeto de controle, várias funções de manipulador padrão são adicionadas automaticamente à classe do controle, incluindo a implementação padrão de [COleControl::DoPropExchange](../mfc/reference/colecontrol-class.md#dopropexchange). O exemplo a seguir mostra o código adicionado às classes criadas com o Assistente de controle ActiveX:

[!code-cpp[NVC_MFC_AxUI#43](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_1.cpp)]

Se você quiser tornar uma propriedade persistente, modifique `DoPropExchange` adicionando uma chamada para a função do exchange de propriedade. O exemplo a seguir demonstra a serialização de uma propriedade Boolean CircleShape personalizada, em que a propriedade CircleShape tem um valor padrão de **verdadeira**:

[!code-cpp[NVC_MFC_AxSer#1](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_2.cpp)]
[!code-cpp[NVC_MFC_AxSer#2](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_3.cpp)]

A tabela a seguir lista as funções de exchange de propriedade possíveis que você pode usar para serializar as propriedades do controle:

|Funções da troca de propriedade|Finalidade|
|---------------------------------|-------------|
|**(PX_Blob)**|Serializa um tipo de propriedade de dados de objeto binário grande (BLOB).|
|**(PX_Bool)**|Serializa um tipo de propriedade booliana.|
|**(PX_Color)**|Serializa uma propriedade de cor do tipo.|
|**(PX_Currency)**|Serializa um tipo **CY** propriedade (moeda).|
|**(PX_Double)**|Serializa um tipo **duplas** propriedade.|
|**(PX_Font)**|Serializa uma propriedade de tipo de fonte.|
|**(PX_Float)**|Serializa um tipo **float** propriedade.|
|**(PX_IUnknown)**|Serializa uma propriedade do tipo `LPUNKNOWN`.|
|**(PX_Long)**|Serializa um tipo **longo** propriedade.|
|**(PX_Picture)**|Serializa um tipo de propriedade de imagem.|
|**(PX_Short)**|Serializa um tipo **curto** propriedade.|
|**(PXstring)**|Serializa um tipo `CString` propriedade.|
|**(PX_ULong)**|Serializa um tipo **ULONG** propriedade.|
|**(PX_UShort)**|Serializa um tipo **USHORT** propriedade.|

Para obter mais informações sobre essas funções da troca de propriedade, consulte [persistência de OLE controles](../mfc/reference/persistence-of-ole-controls.md) na *referência da MFC*.

##  <a name="_core_customizing_the_default_behavior_of_dopropexchange"></a> Personalizando o comportamento padrão do DoPropExchange

A implementação padrão de `DoPropertyExchange` (conforme mostrado no tópico anterior) faz uma chamada para a classe base `COleControl`. Isso serializa o conjunto de propriedades com suporte automaticamente pelo `COleControl`, que usa mais espaço de armazenamento que serializar apenas as propriedades personalizadas do controle. Remover essa chamada permite que seu objeto serializar apenas as propriedades que você considerar importante. Qualquer propriedade de estoque dos Estados implementou o controle não serão serializados quando salvar ou carregar o objeto de controle, a menos que você adicione explicitamente **px _** chama para eles.

##  <a name="_core_implementing_version_support"></a> Implementando o suporte de versão

Suporte de versão permite que um controle ActiveX revisado adicionar novas propriedades persistentes e ainda ser capaz de detectar e carregar o estado persistente criado por uma versão anterior do controle. Para disponibilizar a versão de um controle como parte de seus dados persistentes, chame [COleControl::ExchangeVersion](../mfc/reference/colecontrol-class.md#exchangeversion) no controle do `DoPropExchange` função. Essa chamada é inserida automaticamente se o controle ActiveX tiver sido criado usando o Assistente de controle ActiveX. Ele pode ser removido se não for necessário suporte de versão. No entanto, o custo de tamanho do controle é muito pequeno (4 bytes) para a flexibilidade adicional que fornece suporte de versão.

Se o controle não foi criado com o Assistente de controle ActiveX, adicione uma chamada para `COleControl::ExchangeVersion` inserindo a seguinte linha no início do seu `DoPropExchange` função (antes da chamada para `COleControl::DoPropExchange`):

[!code-cpp[NVC_MFC_AxSer#1](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_2.cpp)]
[!code-cpp[NVC_MFC_AxSer#3](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_4.cpp)]

Você pode usar qualquer **DWORD** como o número de versão. Usam projetos gerados pelo Assistente de controle de ActiveX `_wVerMinor` e `_wVerMajor` como padrão. Esses são constantes globais definidas no arquivo de implementação da classe de controle ActiveX do projeto. No restante do seu `DoPropExchange` função, você pode chamar [CPropExchange::GetVersion](../mfc/reference/cpropexchange-class.md#getversion) a qualquer momento para recuperar a versão que você está salvando ou recuperação.

No exemplo a seguir, a versão 1 deste controle de exemplo tem apenas uma propriedade de "ReleaseDate". Versão 2 adiciona uma propriedade de "OriginalDate". Se o controle é instruído para carregar o estado persistente da versão antiga, ela inicializará a variável de membro para a nova propriedade para um valor padrão.

[!code-cpp[NVC_MFC_AxSer#4](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_5.cpp)]
[!code-cpp[NVC_MFC_AxSer#3](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_4.cpp)]

Por padrão, um controle "converte" os dados antigos para o formato mais recente. Por exemplo, se a versão 2 de um controle carrega os dados que foi salvo pela versão 1, ele gravará o formato da versão 2 quando ele é salvo novamente. Se você deseja que o controle para salvar dados no formato última leitura, passe **falsos** como um terceiro parâmetro ao chamar `ExchangeVersion`. Neste terceiro parâmetro é opcional e é **verdadeira** por padrão.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

