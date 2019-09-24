---
title: Erro RW2002 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RW2002
helpviewer_keywords:
- RW2002
ms.assetid: b1d1a49b-b50b-4b0b-9f09-c7762e2dbe8f
ms.openlocfilehash: 1726e6ce74dfd7b6b0c6e4b69771a826cdf07774
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/24/2019
ms.locfileid: "71230413"
---
# <a name="resource-compiler-error-rw2002"></a>Erro RW2002 (compilador de recurso)

Erro de análise

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. **Tipo de acelerador necessário (ASCII ou VIRTKEY)**

   O `type` campo na instrução **Accelerators** deve conter o valor ASCII ou VIRTKEY.

1. **INÍCIO esperado na tabela do acelerador**

   A palavra-chave **begin** deve seguir imediatamente a palavra-chave **Accelerators** .

1. **INÍCIO esperado na caixa de diálogo**

   A palavra-chave **begin** deve seguir imediatamente a palavra-chave **Dialog** .

1. **INÍCIO esperado no menu**

   A palavra-chave **begin** deve seguir imediatamente a palavra-chave **menu** .

1. **INÍCIO esperado em RCData**

   A palavra-chave **begin** deve seguir imediatamente a palavra-chave **RCDATA** .

1. **Palavra-chave BEGIN esperada na tabela de cadeia de caracteres**

   A palavra-chave **begin** deve seguir imediatamente a palavra-chave **STRINGTABLE** .

1. **Não é possível usar novamente as constantes de cadeia de caracteres**

   Você está usando o mesmo valor duas vezes em uma instrução **STRINGTABLE** . Verifique se você não está misturando valores decimais e hexadecimais sobrepostos. Cada ID em um **STRINGTABLE** deve ser exclusivo. Para obter a eficiência máxima, use constantes contíguas que comecem em um múltiplo de 16.

1. **Caractere de controle fora do intervalo [^ A-^ Z]**

   Um caractere de controle na instrução **Accelerators** é inválido. O caractere após o cursor ( **^** ) deve estar entre a e Z, inclusive.

1. **Menus vazios não são permitidos**

   Uma palavra-chave **end** é exibida antes de qualquer item de menu ser definido na instrução de **menu** . O compilador de recurso não permite menus vazios. Verifique se você não tem aspas abertas na instrução de **menu** .

1. **FIM esperado na caixa de diálogo**

   A palavra-chave **end** deve ocorrer no final de uma instrução de **diálogo** . Verifique se não há aspas abertas restantes da instrução anterior.

1. **FIM esperado no menu**

   A palavra-chave **end** deve vir ao final de uma instrução de **menu** . Verifique se você não tem aspas abertas ou um par incompatível de instruções **begin** e **end** .

1. **Vírgula esperada na tabela do acelerador**

   O compilador de recurso requer uma vírgula entre `event` os campos e *idvalue* na instrução **Accelerators** .

1. **Nome de classe de controle esperado**

   O `class` campo de uma instrução de **controle** na instrução da **caixa de diálogo** deve ser um dos seguintes tipos: BOTÃO, caixa de combinação, editar, caixa de listagem, barra de ROLAgem, estático ou definido pelo usuário. Verifique se a classe está grafada corretamente.

1. **Nome de face da fonte esperado**

   O campo de *tipo* da opção fonte na instrução da **caixa de diálogo** deve ser uma cadeia de caracteres ASCII entre aspas duplas. Este campo especifica o nome de uma fonte.

1. **Valor de ID esperado para MenuItem**

   A instrução de **menu** deve conter um campo de *MenuID* , que especifica o nome ou número que identifica o recurso de menu.

1. **Cadeia de menu esperada**

   Cada instrução **MenuItem** e **Popup** deve conter um campo de *texto* , que é uma cadeia de caracteres entre aspas duplas que especifica o nome do item de menu ou menu pop-up. Uma instrução **SEparadora MenuItem** não requer nenhuma cadeia de caracteres entre aspas.

1. **Valor de comando numérico esperado**

   O compilador de recurso estava esperando um campo *idvalue* numérico na instrução **Accelerators** . Verifique se você usou uma `#define` constante para especificar o valor e se a constante está grafada corretamente.

1. **Constante numérica esperada na tabela de cadeia de caracteres**

   Uma constante numérica, definida em uma `#define` instrução, deve seguir imediatamente a palavra-chave **begin** em uma instrução **STRINGTABLE** .

1. **Tamanho de ponto numérico esperado**

   O campo de *pontos* da opção fonte na instrução de **diálogo** deve ser um valor de tamanho de ponto inteiro.

1. **Constante de caixa de diálogo numérica esperada**

   Uma instrução de **caixa de diálogo** requer valores inteiros para os campos *x, y, Width*e *Height* . Verifique se esses valores estão incluídos após a palavra-chave da **caixa de diálogo** e se eles não são negativos.

1. **Cadeia de caracteres esperada em STRINGTABLE**

   Uma cadeia de caracteres é esperada após cada valor de *stringid* em uma instrução **STRINGTABLE** .

1. **Cadeia de caracteres esperada ou comando acelerador de constante**

   O compilador de recurso não pôde determinar que tipo de chave está sendo configurada para o acelerador. O `event` campo na instrução **aceleradores** pode ser inválido.

1. **Esperando número para ID**

   Esperando um número para o `id` campo de uma instrução de controle na instrução da **caixa de diálogo** . Verifique se você tem um número ou `#define` uma instrução para a ID de controle.

1. **Esperando cadeia de caracteres entre aspas na classe da caixa de diálogo**

   O `class` campo da opção de classe na instrução da **caixa de diálogo** deve ser um número inteiro ou uma cadeia de caracteres entre aspas duplas.

1. **Esperando cadeia de caracteres entre aspas no título da caixa de diálogo**

   O `captiontext` campo da opção de legenda na instrução da **caixa de diálogo** deve ser uma cadeia de caracteres ASCII entre aspas duplas.

1. **Arquivo não encontrado: nome de arquivo**

   O arquivo especificado na linha de comando do compilador de recurso não foi encontrado. Verifique se o arquivo foi movido para outro diretório e se o filename ou o caminho foi digitado corretamente. Os arquivos são pesquisados usando a variável de ambiente **include** ou a configuração do Visual Studio, se disponível.

1. **Os nomes das fontes devem ser ordinais**

   O campo de *pontos* na instrução Font deve ser um inteiro, não uma cadeia de caracteres.

1. **Acelerador inválido**

   Um `event` campo na instrução **Accelerators** não foi reconhecido ou tem mais de dois caracteres de comprimento.

1. **Tipo de acelerador inválido (ASCII ou VIRTKEY)**

   O `type` campo na instrução **Accelerators** deve conter o valor ASCII ou VIRTKEY.

1. **Caractere de controle inválido**

   Um caractere de controle na instrução **Accelerators** é inválido. Um caractere de controle válido consiste em uma letra (somente) após um cursor (^).

1. **Tipo de controle inválido**

   Cada instrução de controle em uma instrução de **caixa de diálogo** deve ser uma das seguintes: CHECKBOX, COMBOBOX, CONTROL, CTEXT, DEFPUSHBUTTON, EDITTEXT, GROUPBOX, ICON, LISTBOX, LTEXT, SUPRESSÃO, RADIOBUTTON, RTEXT, SCROLLBAR. Verifique se essas instruções de controle estão escritas corretamente.

1. **Tipo inválido**

   O tipo de recurso não estava entre os tipos definidos no arquivo WINDOWS. h.

1. **Cadeia de texto ou ordinal esperado no controle**

   O campo de *texto* de uma instrução de **controle** na instrução da **caixa de diálogo** deve ser uma cadeia de caracteres de texto ou uma referência ordinal para o tipo de controle. Se estiver usando um ordinal, verifique se você tem uma `#define` instrução para o controle.

1. **Parênteses incompatíveis**

   Verifique se você fechou todos os parênteses abertos na instrução da **caixa de diálogo** .

1. **Valor inesperado em RCData**

   Os valores de *dados brutos* na instrução **RCDATA** devem ser inteiros ou cadeias de caracteres, cada um separado por uma vírgula. Certifique-se de não deixar uma vírgula ou deixar uma aspa ao contrário de uma cadeia de caracteres.

1. **Subtipo de menu desconhecido**

   O campo de *definição de item* da instrução de **menu** pode conter somente instruções **MenuItem** e **Popup** .