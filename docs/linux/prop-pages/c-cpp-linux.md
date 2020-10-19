---
title: Propriedades do C/C++ (Linux C++)
ms.date: 10/14/2020
description: Descreve as opções de compilação do Linux na página de propriedades do Visual Studio C/C++
ms.assetid: 4bb8894b-c874-4a68-935e-b127d54e484f
f1_keywords: []
ms.openlocfilehash: 0840327b30d94b4845adef7788fd73f4e797775f
ms.sourcegitcommit: f19f02f217b80804ab321d463c76ce6f681abcc6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/19/2020
ms.locfileid: "92176234"
---
# <a name="cc-properties-linux-c"></a>Propriedades do C/C++ (Linux C++)

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="general"></a>Geral

| Propriedade | Descrição | Opções |
|--|--|--|
| Diretórios de Inclusão Adicionais | Especifica um ou mais diretórios a serem adicionados ao caminho de inclusão. Use ponto-e-vírgula para separar vários diretórios. (-I\[path]). |
| Formato de informações de depuração | Especifica o tipo de informações de depuração geradas pelo compilador. | **Nenhum** – não produz nenhuma informação de depuração, portanto, a compilação pode ser mais rápida.<br/>**Mínimo de informações de depuração** – gerar o mínimo de informações de depuração.<br/>**Informações de depuração completas (DWARF2)** – gerar informações de depuração DWARF2.<br/> |
| Nome do arquivo-objeto | Especifica um nome para substituir o nome padrão do arquivo-objeto. Ele pode ser um nome de arquivo ou diretório. (-o [name]). |
| Nível de aviso | Seleciona o rigor que você deseja que o compilador aplique aos erros de código.  Adicione outros sinalizadores diretamente a **Opções Adicionais**. (/w, /Weverything). | **Desligar todos os avisos** – desabilita todos os avisos do compilador.<br/>**EnableAllWarnings** – habilita todos os avisos, incluindo os que estão desabilitados por padrão.<br/> |
| Tratar avisos como erros | Trata todos os avisos do compilador como erros. Para um novo projeto, talvez seja melhor usar /Werror em todas as compilações. Resolva todos os avisos para garantir o menor número possível de defeitos de código de difícil localização. |
| Avisos adicionais do C | Define um conjunto adicional de mensagens de aviso. |
| Avisos adicionais do C++ | Define um conjunto adicional de mensagens de aviso. |
| Habilitar modo detalhado | Quando o modo detalhado está habilitado, imprime mais informações para diagnosticar o build. |
| Compilador C | Especifica o programa a ser invocado durante a compilação de arquivos de origem C ou o caminho para o compilador C no sistema remoto. |
| Compilador C++ | Especifica o programa a ser invocado durante a compilação de arquivos de origem C++ ou o caminho para o compilador C++ no sistema remoto. |
| Tempo limite de compilação | Tempo limite de compilação remota, em milissegundos. |
| Copiar arquivos-objetos | Especifica se é necessário copiar os arquivos-objetos compilados do sistema remoto para o computador local. |
| Máximo de trabalhos de compilação paralela | O número de processos a serem criados em paralelo durante a compilação. O padrão é 1. Se você estiver usando o subsistema do Windows para Linux (WSL) versão 1, o limite será 64. |
| Validar arquitetura | Especifique se deseja verificar se a plataforma para a qual o projeto se destina corresponde ao sistema remoto.|
| Habilitar limpeza de endereço | Compile o programa com o resolvedor de endereço, que é um detector de erro de memória rápida que pode encontrar problemas de memória de tempo de execução, como o uso gratuito, e a execução de verificações fora dos limites.|

## <a name="optimization"></a>Optimization

| Propriedade | Descrição | Opções |
|--|--|--|
| Optimization | Especifica o nível de otimização para o aplicativo. | **Personalizar** – otimização personalizada.<br/>**Desabilitado** – desabilitar a otimização.<br/>**Minimizar tamanho** – otimizar o tamanho.<br/>**Maximizar velocidade** – otimizar a velocidade.<br/>**Otimização total** – otimizações de alto custo. |
| Alias estrito | Considera as regras de nome alternativo mais rígidas.  Um objeto de um tipo nunca é considerado como tendo o mesmo endereço que um objeto de um tipo diferente. |
| Desenrolar loops | Desenrola loops para deixar o aplicativo mais rápido reduzindo o número de branches executados, em detrimento do aumento do tamanho do código. |
| Otimização de tempo de vinculação | Habilita as otimizações entre procedimentos permitindo que o otimizador examine os arquivos-objeto no aplicativo. |
| Omitir ponteiro de quadro | Inibe a criação de ponteiros de quadros na pilha de chamadas. |
| Não há blocos comuns | Aloca até mesmo variáveis globais não inicializadas na seção de dados do arquivo-objeto, em vez de gerá-las como blocos comuns. |

## <a name="preprocessor"></a>Pré-processador

| Propriedade | Descrição |
|--|--|
| Definições do Pré-processador | Define os símbolos de pré-processamento para o arquivo de origem. (-D) |
| Excluir definições do pré-processador | Especifica uma ou mais exclusões de definição do pré-processador.  (-U \[macro]) |
| Excluir todas as definições do pré-processador | Exclui as definições de todos os valores do pré-processador definidos anteriormente.  (-undef) |
| Mostrar inclusões | Gera uma lista de arquivos de inclusão com a saída do compilador.  (-H) |

## <a name="code-generation"></a>Geração de código

| Propriedade | Descrição | Opções |
|--|--|--|
| Código independente da posição | Gera um PIC (código independente de posição) para ser usado em uma biblioteca compartilhada. |
| Estáticos são thread-safe | Emite um código extra para usar as rotinas especificadas no ABI do C++ para inicialização thread-safe de estáticos locais. | **Não** – desabilite os estáticos thread-safe.<br/>**Sim** – habilite os estáticos thread-safe. |
| Otimização de ponto flutuante | Habilita as otimizações de ponto flutuante atenuando a conformidade com o IEEE-754. |
| Métodos embutidos ocultados | Quando essa opção está habilitada, as cópias fora de linha de métodos embutidos são declaradas como `private extern`. |
| Símbolos ocultos por padrão | Todos os símbolos são declarados como `private extern`, a menos que explicitamente marcado para exportação usando a macro `__attribute`. |
| Habilitar exceções do C++ | Especifica o modelo de tratamento de exceção usado pelo compilador. | **Não** – desabilitar o tratamento de exceções.<br/>**Sim** – habilitar tratamento de exceções. |

## <a name="language"></a>Linguagem

| Propriedade | Descrição | Opções |
|--|--|--|
| Habilitar informações de tipo de tempo de execução | Adiciona um código para verificar os tipos de objeto C++ no runtime (informações de tipo de runtime).     (frtti, fno-rtti) |
| Padrão de linguagem C | Determina o padrão de linguagem C. | **Default**<br/>**C89** – padrão de linguagem C89.<br/>**C99** – padrão de linguagem C99.<br/>**C11** – padrão de linguagem C11.<br/>**C99 (dialeto GNU)** – padrão de linguagem C99 (dialeto GNU).<br/>Padrão de linguagem **C11 (DIALETO GNU)** -C11 (dialeto GNU). |
| Padrão de linguagem C++ | Determina o padrão de linguagem C++. | **Default**<br/>**C++03** – padrão de linguagem C++03.<br/>**C++ 11** -padrão de linguagem c++ 11.<br/>**C++14** – padrão de linguagem C++14.<br/>**C++03 (dialeto GNU)** – padrão de linguagem C++03 (dialeto GNU).<br/>**C++11 (dialeto GNU)** – padrão de linguagem C++11 (dialeto GNU).<br/>**C++14 (dialeto GNU)** – padrão de linguagem C++14 (dialeto GNU). |

## <a name="advanced"></a>Avançado

| Propriedade | Descrição | Opções |
|--|--|--|
| Compilar como | Seleciona a opção de linguagem de compilação para arquivos .c e .cpp. (-x c, -x c++) | **Padrão** – detecção com base na extensão .c ou .cpp.<br/>**Compile como c Code** -compile como código c.<br/>**Compile como C++ Code** -compile como código c++. |
| Arquivos de inclusão forçados | Especifica um ou mais arquivos de inclusão forçada (-include \[name]) |

::: moniker-end
