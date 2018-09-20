---
title: Declaração de propriedade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- __property keyword
- declaring properties, C++
- property keyword [C++]
ms.assetid: de169378-a8b8-49f4-a586-76bffc9b5c9f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 019b8eae17952bfe53fd8fbf14db4bafce1bf463
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46438295"
---
# <a name="property-declaration"></a>Declaração da propriedade

A maneira de declarar uma propriedade em uma classe gerenciada foi alterado de extensões gerenciadas para C++ no Visual C++.

Nas extensões gerenciadas de design, cada `set` ou `get` acessador de propriedade é especificado como um método independente. A declaração de cada método é prefixada com o `__property` palavra-chave. O nome do método começa com um `set_` ou `get_` seguido pelo nome real da propriedade (como visível para o usuário). Assim, uma `Vector` fornecendo um `x` coordenar `get` propriedade seria denomine `get_x` e o usuário seria invocá-lo como `x`. Essa convenção de nomenclatura e a especificação separada dos métodos reflete, na verdade, a implementação de tempo de execução subjacente da propriedade. Por exemplo, aqui está nosso `Vector` com um conjunto de propriedades de coordenadas:

```
public __gc __sealed class Vector {
public:
   __property double get_x(){ return _x; }
   __property double get_y(){ return _y; }
   __property double get_z(){ return _z; }

   __property void set_x( double newx ){ _x = newx; }
   __property void set_y( double newy ){ _y = newy; }
   __property void set_z( double newz ){ _z = newz; }
};
```

Isso espalha a funcionalidade associada a uma propriedade e exige que o usuário lexicalmente unificar os conjuntos associados e obtém. Além disso, ela é detalhada. Na nova sintaxe, que é mais semelhante da linguagem c#, o `property` palavra-chave é seguido pelo tipo da propriedade e seu nome não adornado. O `set` e `get` métodos de acesso são colocados dentro de um bloco após o nome da propriedade. Observe que, diferentemente do c#, a assinatura do método de acesso é especificada. Por exemplo, aqui está o exemplo de código acima traduzido para a nova sintaxe.

```
public ref class Vector sealed {
public:
   property double x {
      double get() {
         return _x;
      }

      void set( double newx ) {
         _x = newx;
      }
   } // Note: no semi-colon
};
```

Se os métodos de acesso da propriedade refletem os níveis de acesso distintos - como uma `public get` e uma `private` ou `protected set`, um rótulo de acesso explícito pode ser especificado. Por padrão, o nível de acesso da propriedade reflete que o delimitador de nível de acesso. Por exemplo, na definição acima de `Vector`, ambos os `get` e `set` métodos são `public`. Para tornar o `set` método `protected` ou `private`, a definição deve ser examinada como segue:

```
public ref class Vector sealed {
public:
   property double x {
      double get() {
         return _x;
      }

   private:
      void set( double newx ) {
         _x = newx;
      }

   } // note: extent of private culminates here

// note: dot is a public method of Vector
double dot( const Vector^ wv );

// etc.
};
```

O escopo de uma palavra-chave de acesso dentro de uma propriedade se estende até que a chave de fechamento da propriedade ou a especificação de uma palavra-chave de acesso adicional. Ele não se estende além da definição da propriedade para o nível de acesso delimitador no qual a propriedade está definida. Na declaração acima, por exemplo, `Vector::dot()` é um método público.

Gravar as propriedades get/set para as três `Vector` coordenadas envolve três etapas:

1. Declare um membro de estado particular do tipo apropriado.

1. retorná-lo quando o usuário deseja obter seu valor.

1. Atribua o valor novo.

Na nova sintaxe, uma sintaxe de propriedade abreviada está disponível que automatiza esse padrão de uso:

```
public ref class Vector sealed {
public:
   // equivalent shorthand property syntax
   property double x;
   property double y;
   property double z;
};
```

O efeito colateral interessante da sintaxe de propriedade abreviada é que embora o membro estado backstage é gerado pelo compilador, não é acessível dentro da classe, exceto por meio de acessadores get/set.

## <a name="see-also"></a>Consulte também

[Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)<br/>
[propriedade](../windows/property-cpp-component-extensions.md)