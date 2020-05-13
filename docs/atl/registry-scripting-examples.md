---
title: Exemplos de script do registro
ms.date: 11/04/2016
helpviewer_keywords:
- scripting, examples
- registrar scripts [ATL]
- scripts, Registrar scripts
- registry, Registrar
ms.assetid: b6df80e1-e08b-40ee-9243-9b381b172460
ms.openlocfilehash: 0e225ce28309aa619fd9436d8f4b93e60544e86c
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168742"
---
# <a name="registry-scripting-examples"></a>Exemplos de script do registro

Os exemplos de script neste tópico demonstram como adicionar uma chave ao registro do sistema, registrar o servidor COM do registrador e especificar várias árvores de análise.

## <a name="add-a-key-to-hkey_current_user"></a>Adicionar uma chave a HKEY_CURRENT_USER

A árvore de análise a seguir ilustra um script simples que adiciona uma única chave ao registro do sistema. Em particular, o script adiciona a chave, `MyVeryOwnKey`, ao `HKEY_CURRENT_USER`. Ele também atribui o valor de cadeia de caracteres padrão `HowGoesIt` de à nova chave:

```rgs
HKEY_CURRENT_USER
{
    'MyVeryOwnKey' = s 'HowGoesIt'
}
```

Esse script pode ser facilmente estendido para definir várias subchaves da seguinte maneira:

```rgs
HKCU
{
    'MyVeryOwnKey' = s 'HowGoesIt'
    {
        'HasASubkey'
        {
            'PrettyCool' = d '55'
            val 'ANameValue' = s 'WithANamedValue'
        }
    }
}
```

Agora, o script adiciona uma subchave `HasASubkey`,, `MyVeryOwnKey`para. Para essa subchave, ela adiciona a `PrettyCool` subchave (com um `DWORD` valor padrão de 55) e `ANameValue` o valor nomeado (com um valor de `WithANamedValue`cadeia de caracteres de).

## <a name="register-the-registrar-com-server"></a><a name="_atl_register_the_registrar_com_server"></a>Registrar o servidor COM do registrador

O script a seguir registra o próprio servidor COM do registrador.

```rgs
HKCR
{
    ATL.Registrar = s 'ATL Registrar Class'
    {
        CLSID = s '{44EC053A-400F-11D0-9DCD-00A0C90391D3}'
    }
    NoRemove CLSID
    {
        ForceRemove {44EC053A-400F-11D0-9DCD-00A0C90391D3} = s 'ATL Registrar Class'
        {
            ProgID = s 'ATL.Registrar'
            InprocServer32 = s '%MODULE%'
            {
                val ThreadingModel = s 'Apartment'
            }
        }
    }
}
```

Em tempo de execução, essa árvore de análise `ATL.Registrar` adiciona a `HKEY_CLASSES_ROOT`chave a. Para essa nova chave, ela:

- Especifica `ATL Registrar Class` como o valor de cadeia de caracteres padrão da chave.

- Adiciona `CLSID` uma subchave.

- Especifica `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` para `CLSID`. (Esse valor é o CLSID do registrador para uso `CoCreateInstance`com.)

Como `CLSID` é compartilhado, ele não deve ser removido no modo de cancelamento do registro. A instrução, `NoRemove CLSID`, faz isso indicando que `CLSID` deve ser aberta no modo de registro e ignorada no modo de cancelamento do registro.

A `ForceRemove` instrução fornece uma função de manutenção removendo uma chave e todas as suas subchaves antes de recriar a chave. Isso pode ser útil se os nomes das subchaves tiverem mudado. Neste exemplo de script, `ForceRemove` o verifica se `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` já existe. Se tiver, `ForceRemove`:

- Exclui `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` recursivamente e todas as suas subchaves.

- Cria `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`novamente.

- Adiciona `ATL Registrar Class` como o valor de cadeia de `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`caracteres padrão para.

A árvore de análise agora adiciona duas novas subchaves a `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`. A primeira chave, `ProgID`, obtém um valor de cadeia de caracteres padrão que é o ProgID. A segunda chave, `InprocServer32`, obtém um valor de cadeia de `%MODULE%`caracteres padrão,, que é um valor de pré-processador explicado na seção [usando parâmetros substituíveis (o pré-processador do registrador)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md)deste artigo. `InprocServer32`também obtém um valor nomeado, `ThreadingModel`, com um valor de cadeia `Apartment`de caracteres de.

## <a name="specify-multiple-parse-trees"></a>Especificar várias árvores de análise

Para especificar mais de uma árvore de análise em um script, basta inserir uma árvore no final de outra. Por exemplo, o script a seguir adiciona a chave `MyVeryOwnKey`,, para as árvores de análise `HKEY_CLASSES_ROOT` para `HKEY_CURRENT_USER`e:

```rgs
HKCR
{
    'MyVeryOwnKey' = s 'HowGoesIt'
}
HKEY_CURRENT_USER
{
    'MyVeryOwnKey' = s 'HowGoesIt'
}
```

> [!NOTE]
> Em um script de registrador, 4K é o tamanho máximo do token. (Um token é qualquer elemento reconhecível na sintaxe.) No exemplo de `HKCR`script anterior, `HKEY_CURRENT_USER` `'MyVeryOwnKey'`,, e `'HowGoesIt'` são todos os tokens.

## <a name="see-also"></a>Confira também

[Criando scripts de registrador](../atl/creating-registrar-scripts.md)
