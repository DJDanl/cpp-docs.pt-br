---
title: "Adicionando uma entrada a uma tabela de aceleradores | Microsoft Docs"
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
  - "Adicionar entradas de tabelas de teclas aceleradoras [C++]"
  - "Comando Novo Acelerador"
ms.assetid: 559c2415-8323-4339-9447-6966665f8288
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando uma entrada a uma tabela de aceleradores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### <a name="to-add-an-entry-to-an-accelerator-table"></a>Para adicionar uma entrada para uma tabela de aceleradores  
  
1.  Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).  
  
    > [!NOTE]
    >  Se seu projeto ainda não contém um arquivo. RC, consulte [Criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Clique dentro da tabela de aceleração e escolha **novo Acelerador** no menu de atalho, ou clique na entrada de linha vazia na parte inferior da tabela.  
  
3.  Selecione um [ID](Id%20Property.xml) da lista suspensa na ID de caixa ou digite uma nova ID a **ID** caixa.  
  
4.  Tipo de [chave](../Topic/Accelerator%20Key%20Property.md) você deseja usar como um acelerador ou o botão direito do mouse e escolha **próxima tecla digitada** no menu de atalho para definir uma combinação de teclas (o **próxima tecla digitada** comando também está disponível na **Editar** menu).  
  
5.  Alterar o [modificador](../windows/accelerator-modifier-property.md) e [tipo](../windows/accelerator-type-property.md), se necessário.  
  
6.  Pressione **ENTER**.  
  
    > [!NOTE]
    >  Verifique se todos os aceleradores que você definir são exclusivos. Você pode ter várias combinações de teclas atribuídas para a mesma ID sem efeito negativo, por exemplo, CTRL + P e F8 podem ser atribuídos ao ID_PRINT. No entanto, ter uma combinação de teclas atribuído a mais de uma que ID não funcionarão bem, por exemplo, CTRL + Z atribuído a ID_SPELL_CHECK e ID_THESAURUS.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: usando recursos para localização com o ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editando tabelas de aceleradores](../windows/editing-accelerator-tables.md)   
 [Editor de aceleradores](../Topic/Accelerator%20Editor.md)