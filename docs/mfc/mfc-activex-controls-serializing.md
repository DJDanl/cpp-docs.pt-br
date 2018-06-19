---
title: 'Controles ActiveX MFC: Serializando | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 74d62411747dbe920b772b66d11cd1e2a789c5db
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33353492"
---
# <a name="mfc-activex-controls-serializing"></a>Controles ActiveX MFC: serializando
Este artigo aborda como serializar um controle ActiveX. A serialização é o processo de leitura ou gravação em uma mídia de armazenamento persistente, como um arquivo de disco. A biblioteca Microsoft Foundation Class (MFC) fornece suporte interno para serialização na classe `CObject`. `COleControl` estende esse suporte aos controles ActiveX com o uso de um mecanismo de troca de propriedade.  
  
 Serialização para controles ActiveX é implementada por meio da substituição [COleControl::DoPropExchange](../mfc/reference/colecontrol-class.md#dopropexchange). Essa função, chamado durante o carregamento e salvar o objeto de controle, armazena todas as propriedades implementadas com uma variável de membro ou uma variável de membro com a notificação de alteração.  
  
 Os tópicos a seguir abordam os principais problemas relacionados a serialização de um controle ActiveX:  
  
-   Implementando `DoPropExchange` função para serializar o objeto de controle  
  
-   [Personalizando o processo de serialização](#_core_customizing_the_default_behavior_of_dopropexchange)  
  
-   [Implementando o suporte à versão](#_core_implementing_version_support)  
  
##  <a name="_core_implementing_the_dopropexchange_function"></a> Implementando a função DoPropExchange  
 Quando você usar o Assistente de controle ActiveX para gerar o projeto de controle, várias funções de manipulador padrão são adicionadas automaticamente para a classe de controle, incluindo a implementação padrão de [COleControl::DoPropExchange](../mfc/reference/colecontrol-class.md#dopropexchange). O exemplo a seguir mostra o código adicionado às classes criadas com o Assistente de controle ActiveX:  
  
 [!code-cpp[NVC_MFC_AxUI#43](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_1.cpp)]  
  
 Se você quiser tornar uma propriedade persistente, modifique `DoPropExchange` pela adição de uma chamada para a função de propriedade do exchange. O exemplo a seguir demonstra a serialização de uma propriedade booleana CircleShape personalizada, onde a propriedade CircleShape tem um valor padrão de **TRUE**:  
  
 [!code-cpp[NVC_MFC_AxSer#1](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_2.cpp)]  
[!code-cpp[NVC_MFC_AxSer#2](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_3.cpp)]  
  
 A tabela a seguir lista as funções de exchange de propriedade possíveis que você pode usar para serializar as propriedades do controle:  
  
|Funções de troca de propriedade|Finalidade|  
|---------------------------------|-------------|  
|**(PX_Blob)**|Serializa um tipo de propriedade de objeto binário grande (BLOB) de dados.|  
|**(PX_Bool)**|Serializa um tipo de propriedade booleana.|  
|**(PX_Color)**|Serializa uma propriedade de cor de tipo.|  
|**(PX_Currency)**|Serializa um tipo **CY** propriedade (moeda).|  
|**(PX_Double)**|Serializa um tipo **duplo** propriedade.|  
|**(PX_Font)**|Serializa uma propriedade de tipo de fonte.|  
|**(PX_Float)**|Serializa um tipo **float** propriedade.|  
|**(PX_IUnknown)**|Serializa uma propriedade do tipo `LPUNKNOWN`.|  
|**(PX_Long)**|Serializa um tipo **longo** propriedade.|  
|**(PX_Picture)**|Serializa um tipo de propriedade de imagem.|  
|**(PX_Short)**|Serializa um tipo **curto** propriedade.|  
|**(PXstring)**|Serializa um tipo `CString` propriedade.|  
|**(PX_ULong)**|Serializa um tipo **ULONG** propriedade.|  
|**(PX_UShort)**|Serializa um tipo **USHORT** propriedade.|  
  
 Para obter mais informações sobre essas funções do exchange de propriedade, consulte [persistência de OLE controles](../mfc/reference/persistence-of-ole-controls.md) no *referência MFC*.  
  
##  <a name="_core_customizing_the_default_behavior_of_dopropexchange"></a> Personalizar o comportamento padrão de DoPropExchange  
 A implementação padrão de **DoPropertyExchange** (conforme mostrado no tópico anterior) faz uma chamada para a classe base `COleControl`. Isso serializa o conjunto de propriedades com suporte automaticamente pelo `COleControl`, que usa mais espaço de armazenamento que serializar apenas as propriedades personalizadas do controle. Remover esta chamada permite que o objeto a ser serializado somente as propriedades que você considerar importantes. Qualquer estado de propriedade de estoque implementou o controle não será serializado ao salvar ou carregar o objeto de controle, a menos que você adicione explicitamente **px _** chama para eles.  
  
##  <a name="_core_implementing_version_support"></a> Implementando o suporte à versão  
 Suporte à versão permite um controle ActiveX revisado adicionar novas propriedades persistentes e ainda ser capaz de detectar e carregar o estado persistente criado por uma versão anterior do controle. Para disponibilizar a versão do controle como parte de seus dados persistentes, chame [COleControl::ExchangeVersion](../mfc/reference/colecontrol-class.md#exchangeversion) no controle do `DoPropExchange` função. Esta chamada é inserida automaticamente se o controle ActiveX foi criado usando o Assistente de controle ActiveX. Ele pode ser removido se não for necessário suporte de versão. No entanto, o custo de tamanho do controle é muito pequeno (4 bytes) para garantir flexibilidade que oferece suporte à versão.  
  
 Se o controle não foi criado com o Assistente de controle ActiveX, adicione uma chamada para `COleControl::ExchangeVersion` inserindo a seguinte linha no início do seu `DoPropExchange` função (antes da chamada para `COleControl::DoPropExchange`):  
  
 [!code-cpp[NVC_MFC_AxSer#1](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_2.cpp)]  
[!code-cpp[NVC_MFC_AxSer#3](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_4.cpp)]  
  
 Você pode usar qualquer `DWORD` como o número de versão. Usam projetos gerados pelo Assistente de controle ActiveX **_wVerMinor** e **_wVerMajor** como padrão. Esses são constantes globais definidas no arquivo de implementação da classe de controle ActiveX do projeto. No restante do seu `DoPropExchange` função, você pode chamar [CPropExchange::GetVersion](../mfc/reference/cpropexchange-class.md#getversion) a qualquer momento para recuperar a versão que você está salvando ou recuperar.  
  
 No exemplo a seguir, a versão 1 deste controle de exemplo tem apenas uma propriedade "ReleaseDate". Versão 2 adiciona uma propriedade "OriginalDate". Se o controle é instruído para carregar o estado persistente da versão antiga, ele inicializa a variável de membro para a nova propriedade para um valor padrão.  
  
 [!code-cpp[NVC_MFC_AxSer#4](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_5.cpp)]  
[!code-cpp[NVC_MFC_AxSer#3](../mfc/codesnippet/cpp/mfc-activex-controls-serializing_4.cpp)]  
  
 Por padrão, um controle "converte" dados antigos para o formato mais recente. Por exemplo, se a versão 2 de um controle carrega os dados que foram salvos pela versão 1, ele gravará o formato da versão 2 quando ele é salvo novamente. Se você desejar que o controle para salvar dados em formato última leitura, passar **FALSE** como um terceiro parâmetro ao chamar `ExchangeVersion`. Esse terceiro parâmetro é opcional e é **TRUE** por padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

