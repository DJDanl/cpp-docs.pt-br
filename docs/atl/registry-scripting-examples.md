---
title: Exemplos de scriptamento de registro
ms.date: 11/04/2016
helpviewer_keywords:
- scripting, examples
- registrar scripts [ATL]
- scripts, Registrar scripts
- registry, Registrar
ms.assetid: b6df80e1-e08b-40ee-9243-9b381b172460
ms.openlocfilehash: 7bcdb7076982e2f0bd08f4fd82bb45f21e61ef20
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329338"
---
# <a name="registry-scripting-examples"></a>Exemplos de scriptamento de registro

Os exemplos de scriptneste tópico demonstram como adicionar uma chave ao registro do sistema, registrar o servidor Registrador COM e especificar várias árvores de análise.

## <a name="add-a-key-to-hkey_current_user"></a>Adicione uma chave para HKEY_CURRENT_USER

A árvore de análise a seguir ilustra um script simples que adiciona uma única chave ao registro do sistema. Em particular, o script `MyVeryOwnKey`adiciona `HKEY_CURRENT_USER`a chave, para . Ele também atribui o valor `HowGoesIt` de seqüência padrão à nova chave:

```
HKEY_CURRENT_USER
{
    'MyVeryOwnKey' = s 'HowGoesIt'
}
```

Este script pode ser facilmente estendido para definir várias subchaves da seguinte forma:

```
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

Agora, o script adiciona `HasASubkey`uma `MyVeryOwnKey`subchave, para . A esta subchave, adiciona `PrettyCool` tanto a subchave (com um valor padrão `DWORD` de 55) quanto o `ANameValue` valor nomeado (com um valor de seqüência de `WithANamedValue`).

## <a name="register-the-registrar-com-server"></a><a name="_atl_register_the_registrar_com_server"></a>Registre o Servidor Registrador COM

O script a seguir registra o próprio servidor Registrador COM.

```
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

No tempo de execução, `ATL.Registrar` esta `HKEY_CLASSES_ROOT`árvore de análise adiciona a chave para . Para esta nova chave, então:

- Especifica `ATL Registrar Class` como o valor de seqüência padrão da chave.

- Adiciona `CLSID` como uma subchave.

- Especifica `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` para `CLSID`. (Este valor é o CLSID do `CoCreateInstance`Registrador para uso com .)

Uma `CLSID` vez que é compartilhado, ele não deve ser removido no modo Descadastrar. A declaração, `NoRemove CLSID`, faz `CLSID` isso indicando que deve ser aberta no modo Registrar e ignorada no modo Unregister.

A `ForceRemove` declaração fornece uma função de limpeza removendo uma chave e todas as suas subchaves antes de recriar a chave. Isso pode ser útil se os nomes das subchaves tiverem sido alterados. Neste exemplo de `ForceRemove` script, verifica `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` se já existe. Se isso `ForceRemove`acontecer,

- Exclui recursivamente `{44EC053A-400F-11D0-9DCD-00A0C90391D3}` todas as suas subchaves.

- Recria `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`.

- Adiciona `ATL Registrar Class` como o valor `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`de string padrão para .

A árvore de análise agora adiciona `{44EC053A-400F-11D0-9DCD-00A0C90391D3}`duas novas subchaves a . A primeira `ProgID`tecla, recebe um valor de string padrão que é o ProgID. A segunda `InprocServer32`chave, obtém um `%MODULE%`valor de string padrão, que é um valor de pré-processador explicado na seção, [Usando Parâmetros Substituíveis (Pré-processador do Registrador)](../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md), deste artigo. `InprocServer32`também obtém um `ThreadingModel`valor nomeado, `Apartment`com um valor de seqüência de .

## <a name="specify-multiple-parse-trees"></a>Especificar árvores de parse múltiplas

Para especificar mais de uma árvore de análise em um script, basta colocar uma árvore no final de outra. Por exemplo, o script a `MyVeryOwnKey`seguir adiciona a chave, às árvores de análise para ambos `HKEY_CLASSES_ROOT` e: `HKEY_CURRENT_USER`

```
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
> Em um script Registrador, 4K é o tamanho máximo do token. (Um token é qualquer elemento reconhecível na sintaxe.) No exemplo de `HKCR`scriptanterior, , `HKEY_CURRENT_USER`e `'MyVeryOwnKey'` `'HowGoesIt'` são todos tokens.

## <a name="see-also"></a>Confira também

[Criando scripts de registrador](../atl/creating-registrar-scripts.md)
