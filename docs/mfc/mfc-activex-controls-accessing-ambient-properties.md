---
title: "Controles ActiveX MFC: acessando propriedades ambiente | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX MFC, acessando propriedades de ambiente"
  - "propriedades [MFC], acessando ambiente"
ms.assetid: fdc9db29-e6b0-45d2-a879-8bd60e2058a7
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: acessando propriedades ambiente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve como um controle ActiveX pode acessar as propriedades ambientais do contêiner do controle.  
  
 Um controle pode obter informações sobre seu contêiner acessando as propriedades ou do contêiner.  Essas propriedades expostas características visuais, como cor do plano de fundo do contêiner, a fonte atual usada por contêineres, e características operacionais, como se o contêiner está em modo de usuário ou o modo do designer.  Um controle pode usar as propriedades de ambiente para personalizar a aparência e o comportamento ao contêiner específico em que é inserido.  No entanto, um controle deve nunca suponha que o seu contêiner dará suporte a qualquer propriedade de ambiente específico.  De fato, qualquer contêiner não podem oferecer suporte a nenhuma variável propriedades de todos eles.  Na ausência de uma propriedade de ambiente, um controle deve pressupor um valor razoável padrão.  
  
 Para acessar uma propriedade de ambiente, faça uma chamada a [COleControl::GetAmbientProperty](../Topic/COleControl::GetAmbientProperty.md).  Esta função espera a ID de distribuição para a propriedade variável como o primeiro parâmetro \(o arquivo OLECTL.H define IDs de distribuição para o conjunto de propriedades padrão\) ou.  
  
 Os parâmetros da função de `GetAmbientProperty` é a ID de distribuição, uma marca variante que indicam o tipo de propriedade esperado, e um ponteiro para a memória no valor deve ser retornado.  O tipo de dados que esse ponteiro se refere variar dependendo da marca variante.  A função retorna **Verdadeiro** se o contêiner da suporte à propriedade, se não retorna **Falso**.  
  
 O exemplo de código obtém o valor da propriedade variável chamada “UserMode”. Se a propriedade não tem suporte pelo contêiner, um valor padrão de **Verdadeiro** será assumido:  
  
 [!code-cpp[NVC_MFC_AxUI#30](../mfc/codesnippet/CPP/mfc-activex-controls-accessing-ambient-properties_1.cpp)]  
  
 Para sua conveniência, `COleControl` fornece funções auxiliares que acessam muitas das propriedades ambientais de uso geral e as opções apropriadas de retorno quando as propriedades não estão disponíveis.  Essas funções auxiliares são os seguintes:  
  
-   [COleControl::AmbientBackColor](../Topic/COleControl::AmbientBackColor.md)  
  
-   [AmbientDisplayName](../Topic/COleControl::AmbientDisplayName.md)  
  
-   [AmbientFont](../Topic/COleControl::AmbientFont.md)  
  
    > [!NOTE]
    >  O chamador deve chamar **Release\( \)** na fonte retornado.  
  
-   [AmbientForeColor](../Topic/COleControl::AmbientForeColor.md)  
  
-   [AmbientLocaleID](../Topic/COleControl::AmbientLocaleID.md)  
  
-   [AmbientScaleUnits](../Topic/COleControl::AmbientScaleUnits.md)  
  
-   [AmbientTextAlign](../Topic/COleControl::AmbientTextAlign.md)  
  
-   [AmbientUserMode](../Topic/COleControl::AmbientUserMode.md)  
  
-   [AmbientUIDead](../Topic/COleControl::AmbientUIDead.md)  
  
-   [AmbientShowHatching](../Topic/COleControl::AmbientShowHatching.md)  
  
-   [AmbientShowGrabHandles](../Topic/COleControl::AmbientShowGrabHandles.md)  
  
 Se o valor de uma propriedade de ambiente for alterado \(com alguma ação do contêiner\), a função de membro de **OnAmbientPropertyChanged** de controle será chamada.  Substituir essa função de membro para tratar essa notificação.  O parâmetro para **OnAmbientPropertyChanged** é a ID de expedição de propriedade de ambiente afetada.  O valor desse ID da remessa pode ser **DISPID\_UNKNOWN**, que indica que uma ou mais propriedades de ambiente for alterado, mas informações sobre as propriedades que foi afetada não está disponível.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)