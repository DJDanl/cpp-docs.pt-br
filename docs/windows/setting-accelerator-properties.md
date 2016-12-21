---
title: "Configurando propriedades do acelerador | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "propriedades de acelerador"
  - "Propriedades [C++], propriedades de acelerador"
  - "Tipo de propriedade"
  - "Propriedade de chave"
  - "Propriedade de Modificador"
ms.assetid: 0fce9156-3025-4e18-b034-e219a4c65812
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Configurando propriedades do acelerador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

No Visual C++ .NET, você pode definir propriedades de acelerador no [janela propriedades](../Topic/Properties%20Window.md) a qualquer momento. Você também pode usar o editor de aceleradores para modificar as propriedades de acelerador na tabela de aceleração. As alterações feitas usando a janela Propriedades ou o editor de aceleradores têm o mesmo resultado: edições são refletidas imediatamente na tabela de aceleração.  
  
 Há três propriedades para cada Acelerador [ID](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/3487f185-de96-4b1d-87db-034a52223160/locales/en-US):  
  
-   O [propriedade modificador](../windows/accelerator-modifier-property.md) define o controle de combinações de teclas para o acelerador.  
  
    > [!NOTE]
    >  Na janela Propriedades, essa propriedade aparece como três propriedades booleanas separadas, que pode ser controlada independentemente: Alt, Ctrl ou Shift.  
  
-   O [propriedade de chave](../Topic/Accelerator%20Key%20Property.md) define a chave real para usar como o acelerador.  
  
-   O [a propriedade Type](../windows/accelerator-type-property.md) determina se a chave é interpretada como virtual (VIRTKEY) ou ASCII/ANSI.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: usando recursos para localização com o ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração predefinidas](../windows/predefined-accelerator-keys.md)   
 [Editores de recursos](../mfc/resource-editors.md)   
 [Editor de aceleradores](../Topic/Accelerator%20Editor.md)