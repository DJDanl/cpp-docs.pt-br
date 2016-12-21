---
title: "Op&#231;&#245;es, exportar assistente de controle de ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "vc.codewiz.class.atl.control.options"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de controle de ATL, options"
ms.assetid: 4607c51a-992d-433e-9281-919c6f519a3d
caps.latest.revision: 14
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Op&#231;&#245;es, exportar assistente de controle de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Insira o resumo de “resultados de pesquisa” aqui.  
  
 Use esta página do assistente para definir o tipo de controle que você está criando e o nível de suporte da interface contém.  
  
## Lista UIElement  
 **Tipo de controle**  
 O tipo de controle que você deseja criar.  
  
-   **Controle padrão: Um controle ActiveX.**  
  
-   **controle composto**: Um controle ActiveX que pode conter \(semelhante a uma caixa de diálogo\) outros controles ActiveX ou controles do windows.  Um controle composto inclui o seguinte:  
  
    -   Um modelo para a caixa de diálogo que implementa o controle composto.  
  
    -   Um recurso personalizado, REGISTRO, que registra automaticamente o controle composto quando chamado.  
  
    -   Classe de C\+\+ que implementa o controle composto.  
  
    -   Uma interface COM, expostos pelo controle composto.  
  
    -   Uma página de teste HTML que contém o controle composto.  
  
     Por padrão, este controle define [CComControlBase::m\_bWindowOnly](../Topic/CComControlBase::m_bWindowOnly.md) como true, para indicar que isso é um controle da janela.  Implementa um mapa do coletor.  Para mais informações, consulte [Suporte para controle DHTML](../../atl/atl-support-for-dhtml-controls.md).  
  
-   **Controle HTML dinâmico \(DHTML\)**: Um controle de ATL DHTML especifica a interface do usuário, usando HTML.  A classe de DHTML interface de usuário contém um mapa de COM.  Por padrão, este controle define [CComControlBase::m\_bWindowOnly](../Topic/CComControlBase::m_bWindowOnly.md) como true, para indicar que isso é um controle da janela.  
  
     Para mais informações, consulte [Identificar os elementos do projeto de controle DHTML](../../atl/identifying-the-elements-of-the-dhtml-control-project.md).  
  
 **controle mínimo**  
 Suporta apenas as interfaces que são necessários para determinar a maioria de contêiner.  Você pode definir **controle mínimo** para alguns dos tipos de controle: você pode criar um controle padrão mínimo, um controle composto mínimo, ou um controle mínimo de DHTML.  
  
 **Agregado**  
 Adiciona suporte de agregação para o controle que você está criando.  Para mais informações, consulte [Agregado](../../atl/aggregation.md).  
  
-   **Sim**: Criar um controle que pode ser agregado.  
  
-   **Não**: Criar um controle que não pode ser agregado.  
  
-   **somente**: Criar um controle que pode apenas ser instanciado com a agregação.  
  
 **Modelo de threads**  
 Especifica que o modelo de segmentação usado pelo controle.  
  
-   **Única**: O controle será executado somente no segmento principal COM.  
  
-   **Apartment**: O controle pode ser criado em qualquer single thread apartment.  a opção.  
  
 **Interface**  
 O tipo de interface expõe de este controle para o contêiner.  
  
-   **Double**: Cria uma interface que expõe propriedades e métodos com `IDispatch` e diretamente com o VTBL.  
  
-   **Personalizar**: Cria uma interface que expõe métodos diretamente com um VTBL.  
  
     Se você selecionar **Personalizar**, então você pode especificar que o controle é **automação compatível**.  Se você selecionar **automação compatível**, então o assistente adicionar o atributo de [oleautomation](../../windows/oleautomation.md) a interface IDL no, e a interface pode ser empacotado pelo empacotador universal em oleaut32.dll.  Consulte [Detalhes de empacotamento](http://msdn.microsoft.com/library/windows/desktop/ms692621) em [!INCLUDE[winsdkshort](../../atl/reference/includes/winsdkshort_md.md)] para mais informações.  
  
     Além de isso, se você selecionar **automação compatível**, então quaisquer parâmetros para todos os métodos no controle deve ser **VARIANT** correspondente.  
  
 **Suporte**  
 Define diversos suporte adicional para o controle.  
  
-   **pontos de conexão**: Permite pontos de conexão para o objeto fazendo a classe de objeto deriva de e [IConnectionPointContainerImpl](../Topic/IConnectionPointContainerImpl%20Class.md) de permitir que expõe uma interface de origem.  
  
-   **licenciado**: Adiciona suporte para o controle para [licenciamento](http://msdn.microsoft.com/library/windows/desktop/ms690543).  Os controles licenciadas só podem ser hospedados se o cliente tem uma licença correta.  
  
## Consulte também  
 [Assistente de controle de ATL](../../atl/reference/atl-control-wizard.md)