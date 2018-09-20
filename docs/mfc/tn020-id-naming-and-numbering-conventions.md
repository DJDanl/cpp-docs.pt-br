---
title: 'TN020: ID de nomenclatura e numeração convenções | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.id
dev_langs:
- C++
helpviewer_keywords:
- TN020
- resource identifiers, naming and numbering
- resource identifiers
ms.assetid: aecbd2cf-68b3-47f6-ae21-b1f507917245
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f19d79b7946e3f2b4fda0b2651ce8d2099373d93
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46433576"
---
# <a name="tn020-id-naming-and-numbering-conventions"></a>TN020: convenções de nomenclatura de ID e numeração

Essa observação descreve a nomenclatura de ID e numeração convenções que usa o MFC 2.0 para recursos, comandos, cadeias de caracteres, controles e janelas filho.

A ID do MFC de nomenclatura e numeração convenções destinam-se para atender aos seguintes requisitos:

- Fornece um padrão de nomenclatura de ID consistente usado em toda a biblioteca do MFC e aplicativos MFC que são compatíveis com o editor de recursos do Visual C++. Isso torna mais fácil para o programador de interpretar o tipo e a origem de um recurso da sua ID.

- Enfatize a relação de 1 para 1 forte entre determinados tipos de IDs.

- Em conformidade com padrões já amplamente usados para nomenclatura de IDs no Windows.

- O espaço de numeração de ID de partição. Números de ID podem ser atribuídos pelo programador, MFC, Windows e recursos do Visual C++ editados. Particionamento apropriados o ajudará a evitar a duplicação de números de ID.

## <a name="the-id-prefix-naming-convention"></a>A convenção de nomenclatura de prefixo de ID

Vários tipos de IDs podem ocorrer em um aplicativo. A convenção de nomenclatura de ID de MFC define prefixos diferentes para diferentes tipos de recursos.

Para indicar uma ID de recurso que se aplica a vários tipos de recurso, o MFC usa o prefixo "IDR". Por exemplo, para uma janela de quadro determinado, MFC usa o mesmo prefixo "IDR" para indicar um recurso de menu, acelerador, cadeia de caracteres e ícone. A tabela a seguir mostra os vários prefixos e seu uso:

|Prefixo|Use|
|------------|---------|
|IDR|Para vários tipos de recurso (principalmente usados para menus, aceleradores e faixas de opções).|
|IDD _|Para recursos de modelo de caixa de diálogo (por exemplo, IDD_DIALOG1).|
|IDC|Para recursos do cursor.|
|IDI_|Para recursos de ícone.|
|IDB_|Para recursos do bitmap.|
|IDS _|Para recursos de cadeia de caracteres.|

Dentro de um recurso de caixa de diálogo, o MFC segue as seguintes convenções:

|Prefixo ou rótulo|Use|
|---------------------|---------|
|IDOK, IDCANCEL|Para o botão de ação padrão IDs.|
|IDC|Para outros controles de caixa de diálogo.|

O prefixo "IDC" também é usado para cursores. Esse conflito de nomeação não é geralmente um problema porque um aplicativo típico terá alguns cursores e muitos controles de caixa de diálogo.

Dentro de um recurso de menu, o MFC segue as seguintes convenções:

|Prefixo|Use|
|------------|---------|
|IDM_|Para itens de menu que não usam a arquitetura de comando do MFC.|
|ID _|Comandos de menu que usam a arquitetura de comando do MFC.|

Comandos a seguir a arquitetura de comando do MFC devem ter um manipulador de comando ON_COMMAND e podem ter um manipulador de ON_UPDATE_COMMAND_UI. Se esses manipuladores de comando seguem a arquitetura de comando do MFC, eles funcionarão corretamente se elas são associadas a um comando de menu, um botão de barra de ferramentas ou um botão de barra da caixa de diálogo. O mesmo prefixo de "ID _" também é usado para uma sequência de prompt de menu é exibida na barra de mensagens do programa. A maioria dos itens de menu em seu aplicativo deve seguir as convenções de comando do MFC. Todas as IDs de comando padrão (por exemplo, ID_FILE_NEW) seguem Esta convenção.

MFC também usa "IDP_" como uma forma especializada de cadeias de caracteres (em vez de "IDs _"). Cadeias de caracteres com o prefixo "IDP_" são prompts, ou seja, cadeias de caracteres usadas em caixas de mensagem. Cadeias de caracteres "IDP_" podem conter "%1" e "%2" como espaços reservados de cadeias de caracteres determinadas pelo programa. Cadeias de caracteres "IDP_" geralmente têm tópicos da Ajuda associados a eles, e cadeias de caracteres "IDs _" não. Cadeias de caracteres "IDP_" sempre são localizadas e cadeias de caracteres "IDs _" não podem ser localizadas.

A biblioteca MFC também usa o prefixo "IDW_" como uma forma especializada de IDs (em vez de "IDC") de controle. Essas IDs são atribuídas a janelas filho, como modos de exibição e divisores pelas classes do framework. IDs de implementação do MFC são prefixadas com "AFX_".

## <a name="the-id-numbering-convention"></a>A convenção de numeração de ID

A tabela a seguir lista os intervalos válidos para as IDs dos tipos específicos. Alguns dos limites são os limites de implementação técnica e outros são convenções que são projetadas para impedir suas IDs de colisão com IDs predefinidas do Windows ou MFC implementações padrão.

É altamente recomendável que você defina todas as IDs de dentro dos intervalos recomendados. O limite inferior desses intervalos é 1, como 0 não é usado. É recomendável que você use a convenção comum e usa 100 ou 101 como a primeira ID.

|Prefixo|Tipo de recurso|Intervalo válido|
|------------|-------------------|-----------------|
|IDR|vários|1 a 0x6FFF|
|IDD _|modelos de caixa de diálogo|1 a 0x6FFF|
|IDC, IDI_, IDB_|cursores, ícones, bitmaps|1 a 0x6FFF|
|IDS _, IDP_|cadeias de caracteres gerais|1 a 0x7FFF|
|ID _|comandos|0x8000 por meio de 0xDFFF|
|IDC|controles|8 a 0xDFFF|

Motivos para esses limites de intervalo:

- Por convenção, o valor da ID igual a 0 não é usado.

- Limitações de implementação do Windows restringem as IDs para ser menor ou igual a 0x7FFF verdadeira do recurso.

- Estrutura interna do MFC reserva esses intervalos:

   - 0x7000 por meio de 0x7FFF (consulte afxres. h)

   - 0xE000 por meio de 0xEFFF (consulte afxres. h)

   - 16000 por meio de 18000 (consulte afxribbonres.h)

     Esses intervalos podem mudar no futuro implementações MFC.

- Vários comandos de sistema do Windows usam o intervalo de 0xF000 a 0xFFFF.

- IDs de controle de 1 a 7 são reservadas para controles padrão como IDOK e IDCANCEL.

- O intervalo de 0x8000 a 0xFFFF para cadeias de caracteres é reservado para prompts de menu para comandos.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

