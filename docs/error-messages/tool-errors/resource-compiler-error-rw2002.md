---
title: RW2002 de erro do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RW2002
dev_langs:
- C++
helpviewer_keywords:
- RW2002
ms.assetid: b1d1a49b-b50b-4b0b-9f09-c7762e2dbe8f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b90a0800708af41037325204a00c808bec2a7d20
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50080852"
---
# <a name="resource-compiler-error-rw2002"></a>Erro RW2002 (compilador de recurso)

Erro de análise

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. **Tipo de acelerador necessária (ASCII ou VIRTKEY)**

   O `type` campo de **ACELERADORES** declaração deve conter o valor de ASCII ou VIRTKEY.

1. **INÍCIO esperado na tabela de aceleradores**

   O **começar** palavra-chave deve vir logo após o **ACELERADORES** palavra-chave.

1. **INÍCIO esperado na caixa de diálogo**

   O **começar** palavra-chave deve vir logo após o **caixa de diálogo** palavra-chave.

1. **INÍCIO esperado no menu**

   O **começar** palavra-chave deve vir logo após o **MENU** palavra-chave.

1. **INÍCIO esperado em RCData**

   O **começar** palavra-chave deve vir logo após o **RCDATA** palavra-chave.

1. **COMEÇAR esperado na tabela de cadeia de caracteres de palavra-chave**

   O **começar** palavra-chave deve vir logo após o **STRINGTABLE** palavra-chave.

1. **não é possível usar novamente as constantes de cadeia de caracteres**

   Você estiver usando o mesmo valor de duas vezes em uma **STRINGTABLE** instrução. Verifique se que você está misturando não sobrepostos valores decimais e hexadecimais. Cada ID em um **STRINGTABLE** deve ser exclusivo. Para obter eficiência máxima, use constantes contíguas que começam em um múltiplo de 16.

1. **Caractere fora do intervalo de controle [^ A - ^ Z]**

   Um caractere de controle na **ACELERADORES** instrução é inválida. O caractere que segue o cursor (**^**) deve estar entre A e Z, inclusivo.

9. **menus vazios não permitidos**

   Uma **final** palavra-chave aparece antes de quaisquer itens de menu são definidos na **MENU** instrução. O compilador de recurso não permite que os menus vazios. Verifique se você não tem qualquer aspas abertas dentro de **MENU** instrução.

10. **TÉRMINO esperado na caixa de diálogo**

   O **final** palavra-chave deve ocorrer no final de uma **caixa de diálogo** instrução. Verifique se há sem aspas abertas à esquerda da instrução anterior.

11. **TÉRMINO esperado no menu**

   O **final** palavra-chave deve vir no final de uma **MENU** instrução. Verifique se você não tem qualquer aspas abertas ou um par incompatível de **começar** e **final** instruções.

12. **Vírgula esperada na tabela do acelerador**

   O compilador de recurso exige uma vírgula entre os `event` e *idvalue* campos no **ACELERADORES** instrução.

13. **nome de classe de controle esperado**

   O `class` campo de um **controle** instrução no **caixa de diálogo** instrução deve ser um dos seguintes tipos: botão, COMBOBOX, editar, LISTBOX, barra de ROLAGEM, estático, ou definido pelo usuário. Verifique se que a classe está escrita corretamente.

14. **Esperado nome de face da fonte**

   O *face de tipos* campo da opção de fonte na **caixa de diálogo** instrução deve ser uma cadeia de caracteres ASCII entre aspas duplas. Este campo especifica o nome de uma fonte.

15. **Valor de ID esperado para menuitem**

   O **menus** declaração deve conter um *menuID* campo, que especifica o nome ou número que identifica o recurso de menu.

16. **Cadeia de caracteres esperada de menu**

   Cada **MENUITEM** e **pop-up** instrução deve conter um *texto* campo, que é uma cadeia de caracteres entre aspas duplas que especifica o nome do item de menu ou pop-up menu. Um **MENUITEM SEPARADOR** instrução não requer nenhuma cadeia de caracteres entre aspas.

17. **esperado um valor numérico de comando**

   O compilador de recurso estava esperando um numérico *idvalue* campo o **ACELERADORES** instrução. Certifique-se de que você tenha usado um `#define` constante para especificar o valor e que a constante está escrita corretamente.

18. **Esperada constante numérica na tabela de cadeia de caracteres**

   Uma constante numérica, definido em um `#define` instrução, deve seguir imediatamente o **BEGIN** palavra-chave em um **STRINGTABLE** instrução.

19. **Tamanho de ponto numérico esperado**

   O *pointsize* campo da opção de fonte na **caixa de diálogo** instrução deve ser um valor de tamanho de ponto inteiro.

20. **esperada constante numérica da caixa de diálogo**

   Um **caixa de diálogo** instrução requer valores inteiros para o *x, y, largura*, e *altura* campos. Certifique-se de que esses valores são incluídos após o **caixa de diálogo** palavra-chave e que não são negativos.

21. **A cadeia de caracteres esperada em STRINGTABLE**

   Uma cadeia de caracteres é esperada depois de cada *stringid* valor em uma **STRINGTABLE** instrução.

22. **Cadeia de caracteres esperada ou o comando de aceleração constante**

   O compilador de recurso não foi capaz de determinar que tipo de chave está sendo configurado para o acelerador. O `event` campo de **ACELERADORES** instrução pode ser inválida.

23. **Esperando que o número de ID**

   Esperando um número para o `id` campo de uma instrução de controle em de **caixa de diálogo** instrução. Verifique se você tem um número ou `#define` instrução para a ID do controle.

24. **Esperando cadeia de caracteres entre aspas na classe de caixa de diálogo**

   O `class` campo da opção na classe de **caixa de diálogo** instrução deve ser um inteiro ou uma cadeia de caracteres entre aspas duplas.

25. **Esperando cadeia de caracteres entre aspas no título da caixa de diálogo**

   O `captiontext` campo da opção legenda os **caixa de diálogo** instrução deve ser uma cadeia de caracteres ASCII entre aspas duplas.

26. **arquivo não encontrado: nome de arquivo**

   O arquivo especificado na linha de comando do compilador de recurso não foi encontrado. Verifique se o arquivo foi movido para outro diretório e se o nome de arquivo ou caminho esteja digitado corretamente. Arquivos são pesquisados para usar o **INCLUDE** variável de ambiente ou a configuração da Bancada de trabalho Visual, se disponível.

27. **Os nomes de fonte devem ser números ordinais**

   O *pointsize* campo na instrução de fonte deve ser um inteiro, não uma cadeia de caracteres.

28. **Acelerador inválido**

   Uma `event` campo de **ACELERADORES** instrução não foi reconhecida ou foi mais de dois caracteres de comprimento.

29. **Tipo de acelerador inválido (ASCII ou VIRTKEY)**

   O `type` campo de **ACELERADORES** declaração deve conter o valor de ASCII ou VIRTKEY.

30. **caractere de controle inválido**

   Um caractere de controle na **ACELERADORES** instrução é inválida. Um caractere de controle válido consiste em uma letra, um acento circunflexo (^) a seguir (somente).

31. **Tipo de controle inválido**

   Cada instrução de controle em uma **caixa de diálogo** instrução deve ser um dos seguintes: caixa de seleção, caixa de COMBINAÇÃO, controle, CTEXT, DEFPUSHBUTTON, EDITTEXT, GROUPBOX, ícone, LISTBOX, LTEXT, PUSHBUTTON, RADIOBUTTON, RTEXT, barra de ROLAGEM. Verifique se essas instruções de controle foram escritas corretamente.

32. **Tipo inválido**

   O tipo de recurso não estava entre os tipos definidos no arquivo Windows. h.

33. **Cadeia de caracteres de texto ou ordinal esperado no controle**

   O *texto* campo de uma **controle** instrução no **caixa de diálogo** instrução deve ser uma cadeia de caracteres de texto ou uma referência ordinal para o tipo de controle. Se usando um ordinal, verifique se você tiver um `#define` instrução para o controle.

34. **Parênteses incompatíveis**

   Certifique-se de ter fechado todos os parênteses de abertura **caixa de diálogo** instrução.

35. **Valor inesperado na RCData**

   O *dados brutos* os valores na **RCDATA** instrução deve ser números inteiros ou cadeias de caracteres, cada um separado por uma vírgula. Verifique se você não deixe de fora de uma vírgula ou deixe de fora de aspas em torno de uma cadeia de caracteres.

36. **Subtipo de menu desconhecido**

   O *definição de item* campo da **MENU** instrução pode conter apenas **MENUITEM** e **pop-up** instruções.