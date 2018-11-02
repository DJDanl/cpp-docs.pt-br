---
title: Eventos de controle padrão
ms.date: 11/04/2016
helpviewer_keywords:
- Dialog Editor [C++], default control events
- controls [C++], default control events
- events [C++], controls
- dialog box controls [C++], events
ms.assetid: 75556b23-18f5-4390-97a4-2ecad3309741
ms.openlocfilehash: 8cd0102be240bc98cf7900653b8fbb714e2a99a1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50520400"
---
# <a name="default-control-events"></a>Eventos de controle padrão

Os seguintes nomes de controle têm os eventos padrão que acompanha este artigo:

|Nome do controle|Evento padrão|
|------------------|-------------------|
|Animar|ACN_START|
|Caixa de seleção|BN_CLICKED|
|Caixa de combinação|CBN_SELCHANGE|
|Personalizado|TTN_GETDISPINFO|
|Seletor de data e hora|DTN_DATETIMECHANGE|
|Caixa de edição|EVENTO EN_CHANGE|
|Caixa de grupo|(Não aplicável)|
|Tecla de acesso|NM_OUTOFMEMORY|
|Endereço IP|IPN_FIELDCHANGED|
|Lista|LVN_ITEMCHANGE|
|Caixa de listagem|LBN_SELCHANGE|
|Calendário mensal|MCN_SELCHANGE|
|Controle de imagem|(Não aplicável)|
|Progresso|NM_CUSTOMDRAW|
|Botão de ação|BN_CLICKED|
|Botão de opção|BN_CLICKED|
|Edição avançada|EVENTO EN_CHANGE|
|Barra de rolagem|NM_THEMECHANGED|
|Controle deslizante|NM_CUSTOMDRAW|
|Rotação|UDN_DELTAPOS|
|Texto estático|(Não aplicável)|
|Tabulação|TCN_SELCHANGE|
|Árvore|TVN_SELCHANGE|

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Definindo variáveis de membro para controles de caixa de diálogo](../windows/defining-member-variables-for-dialog-controls.md)<br/>
[Tipos de mensagem associados a objetos da interface do usuário](../mfc/reference/message-types-associated-with-user-interface-objects.md)<br/>
[Editando um manipulador de mensagens](../mfc/reference/editing-a-message-handler.md)<br/>
[Definindo um manipulador de mensagens para uma mensagem refletida](../mfc/reference/defining-a-message-handler-for-a-reflected-message.md)<br/>
[Declarando uma variável com base na nova classe de controle](../mfc/reference/declaring-a-variable-based-on-your-new-control-class.md)<br/>
[Substituindo uma função virtual](../ide/overriding-a-virtual-function-visual-cpp.md)